// Docsify字体加载优化插件
(function() {
  // 注册为Docsify插件
  if (typeof window.$docsify === 'undefined') {
    return;
  }

  // 字体配置
  const FONT_CONFIG = {
    zhongSong: {
      family: 'zhongsong',
      url: 'public/fonts/zs.ttf',
      format: 'truetype',
      display: 'swap'
    }
  };

  // 创建Docsify插件
  const fontOptimizerPlugin = function(hook, vm) {
    
    // 在Docsify初始化之前添加样式
    hook.init(function() {
      addFontLoadingStyles();
    });

    // 在页面挂载后优化字体加载
    hook.mounted(function() {
      optimizeFontLoading();
    });

    // 每次路由变化后重新应用字体
    hook.doneEach(function() {
      ensureFontApplied();
    });
  };

  // 添加字体加载样式
  function addFontLoadingStyles() {
    const style = document.createElement('style');
    style.textContent = `
      /* 字体加载优化样式 */
      .docsify-font-loading body {
        font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, "PingFang SC", "Hiragino Sans GB", "Microsoft YaHei", sans-serif;
        transition: font-family 0.2s ease;
      }
      
      .docsify-font-loaded body {
        font-family: "KaTeX_Main", "zhongsong", -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, "PingFang SC", "Hiragino Sans GB", "Microsoft YaHei", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol";
      }
      
      /* 字体加载指示器 */
      .font-loading-bar {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 2px;
        background: linear-gradient(90deg, transparent, var(--theme-color), transparent);
        transform: translateX(-100%);
        transition: transform 0.3s ease;
        z-index: 9999;
        pointer-events: none;
      }
      
      .font-loading-bar.active {
        transform: translateX(0);
      }
      
      .font-loading-bar.completed {
        transform: translateX(100%);
      }
    `;
    document.head.appendChild(style);
  }

  // 优化字体加载
  function optimizeFontLoading() {
    // 添加加载指示器
    const loadingBar = document.createElement('div');
    loadingBar.className = 'font-loading-bar active';
    document.body.appendChild(loadingBar);

    // 使用Font Loading API加载华文中宋
    if (document.fonts && FontFace) {
      const zhongSongFont = new FontFace(
        FONT_CONFIG.zhongSong.family,
        `url(${FONT_CONFIG.zhongSong.url})`,
        {
          style: 'normal',
          weight: 'normal',
          display: 'swap'
        }
      );

      zhongSongFont.load().then(() => {
        document.fonts.add(zhongSongFont);
        
        // 应用字体到body
        document.body.classList.add('docsify-font-loaded');
        
        // 隐藏加载指示器
        setTimeout(() => {
          loadingBar.classList.add('completed');
          setTimeout(() => {
            if (loadingBar.parentNode) {
              loadingBar.parentNode.removeChild(loadingBar);
            }
          }, 300);
        }, 100);
        
      }).catch(error => {
        console.warn('华文中宋字体加载失败，使用系统字体:', error);
        if (loadingBar.parentNode) {
          loadingBar.parentNode.removeChild(loadingBar);
        }
      });
    } else {
      // 降级方案：直接使用CSS加载
      const fallbackLink = document.createElement('link');
      fallbackLink.rel = 'stylesheet';
      fallbackLink.href = 'data:text/css;charset=utf-8,' + encodeURIComponent(`
        @font-face {
          font-family: "zhongsong";
          src: url('${FONT_CONFIG.zhongSong.url}') format('${FONT_CONFIG.zhongSong.format}');
          font-weight: normal;
          font-style: normal;
          font-display: swap;
        }
      `);
      document.head.appendChild(fallbackLink);
    }
  }

  // 确保字体在每个页面都应用
  function ensureFontApplied() {
    // Docsify会重新渲染内容，确保字体样式正确应用
    if (document.body.classList.contains('docsify-font-loaded')) {
      // 字体已加载，无需操作
    } else {
      // 检查字体是否已可用
      if (document.fonts && document.fonts.check('1em zhongsong')) {
        document.body.classList.add('docsify-font-loaded');
      }
    }
  }

  // 注册插件到Docsify
  if (window.$docsify) {
    if (!window.$docsify.plugins) {
      window.$docsify.plugins = [];
    }
    window.$docsify.plugins.push(fontOptimizerPlugin);
  }

  // 如果Docsify未初始化，延迟注册
  document.addEventListener('DOMContentLoaded', function() {
    if (window.$docsify && window.$docsify.plugins) {
      window.$docsify.plugins.push(fontOptimizerPlugin);
    }
  });

})();