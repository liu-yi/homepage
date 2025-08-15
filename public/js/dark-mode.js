// 暗黑模式切换功能 - 极简可靠版
(function() {
    const THEME_KEY = 'theme-preference';
    
    function getCurrentTheme() {
        return localStorage.getItem(THEME_KEY) || 
               (window.matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'light');
    }
    
    function setTheme(theme) {
        document.documentElement.setAttribute('data-theme', theme);
        document.body.setAttribute('data-theme', theme);
        localStorage.setItem(THEME_KEY, theme);
        
        // 更新所有切换按钮的状态
        updateAllToggleButtons(theme);
    }
    
    function updateAllToggleButtons(theme) {
        // 更新导航栏中的切换按钮
        const navbarToggle = document.getElementById('toggle-track') || 
                            document.querySelector('.sidebar-nav #toggle-track') ||
                            document.querySelector('.theme-toggle-top #toggle-track');
        if (navbarToggle) {
            navbarToggle.classList.toggle('dark-mode', theme === 'dark');
        }
        
        // 更新移动端按钮图标
        const mobileToggle = document.querySelector('.mobile-theme-toggle');
        if (mobileToggle) {
            const icon = mobileToggle.querySelector('.theme-icon-svg');
            if (icon) {
                if (theme === 'dark') {
                    // Moon icon for dark mode
                    icon.innerHTML = '<path d="M21 12.79A9 9 0 1111.21 3 7 7 0 0021 12.79z"/>';
                } else {
                    // Sun icon for light mode
                    icon.innerHTML = '<path d="M12 2v2M12 20v2M4.93 4.93l1.41 1.41M17.66 17.66l1.41 1.41M2 12h2M20 12h2M6.34 17.66l-1.41 1.41M19.07 4.93l-1.41 1.41M12 17a5 5 0 100-10 5 5 0 000 10z"/>';
                }
            }
            mobileToggle.setAttribute('title', theme === 'dark' ? '切换到浅色模式' : '切换到深色模式');
        }
        
        // 更新原来的主题切换按钮（如果存在）
        const originalToggle = document.querySelector('.theme-toggle');
        if (originalToggle) {
            originalToggle.setAttribute('title', theme === 'dark' ? '切换到浅色模式' : '切换到深色模式');
        }
    }
    
    function toggleTheme() {
        const current = getCurrentTheme();
        const newTheme = current === 'dark' ? 'light' : 'dark';
        setTheme(newTheme);
    }
    
    // 初始化主题
    const initialTheme = getCurrentTheme();
    setTheme(initialTheme);
    
    // 绑定点击事件 - 针对导航栏的切换按钮和移动端按钮
    function bindEvents() {
        // 查找导航栏中的切换按钮
        const navbarToggle = document.getElementById('toggle-track') || 
                            document.querySelector('.sidebar-nav #toggle-track') ||
                            document.querySelector('.theme-toggle-top #toggle-track');
        
        if (navbarToggle) {
            navbarToggle.onclick = toggleTheme;
            navbarToggle.style.cursor = 'pointer';
            
            // 关键：同步当前主题状态到按钮
            const currentTheme = getCurrentTheme();
            navbarToggle.classList.toggle('dark-mode', currentTheme === 'dark');
            
            console.log('导航栏主题切换按钮已绑定，当前主题：' + currentTheme);
        }
        
        // 绑定移动端主题切换按钮
        const mobileToggle = document.querySelector('.mobile-theme-toggle');
        if (mobileToggle) {
            mobileToggle.onclick = toggleTheme;
            mobileToggle.style.cursor = 'pointer';
            
            // 更新移动端按钮的图标状态
            const currentTheme = getCurrentTheme();
            mobileToggle.setAttribute('title', currentTheme === 'dark' ? '切换到浅色模式' : '切换到深色模式');
            
            console.log('移动端主题切换按钮已绑定');
        }
        
        // 绑定原来的主题切换按钮（如果存在）
        const originalToggle = document.querySelector('.theme-toggle');
        if (originalToggle) {
            originalToggle.onclick = toggleTheme;
            originalToggle.style.cursor = 'pointer';
            
            console.log('原来主题切换按钮已绑定');
        }
    }
    
    // 立即绑定，并支持Docsify
    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', bindEvents);
    } else {
        bindEvents();
    }
    
    // Docsify支持 - 专门针对导航栏
    if (window.$docsify) {
        window.$docsify.plugins = (window.$docsify.plugins || []).concat([
            function(hook) {
                hook.doneEach(function() {
                    // 等待Docsify完全渲染导航栏
                    setTimeout(bindEvents, 100);
                });
                
                hook.mounted(function() {
                    // 页面首次加载时
                    setTimeout(bindEvents, 200);
                });
            }
        ]);
    }
    
    // 监听系统主题变化
    window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', function(e) {
        // 只有在用户没有手动设置主题时才跟随系统变化
        if (!localStorage.getItem(THEME_KEY)) {
            const newTheme = e.matches ? 'dark' : 'light';
            setTheme(newTheme);
        }
    });
    
})();