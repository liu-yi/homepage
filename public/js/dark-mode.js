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
        
        // 更新开关状态
        const toggle = document.getElementById('toggle-track');
        if (toggle) {
            toggle.classList.toggle('dark-mode', theme === 'dark');
        }
    }
    
    function toggleTheme() {
        const current = getCurrentTheme();
        const newTheme = current === 'dark' ? 'light' : 'dark';
        setTheme(newTheme);
    }
    
    // 初始化主题
    setTheme(getCurrentTheme());
    
    // 绑定点击事件 - 针对导航栏的切换按钮
    function bindEvents() {
        // 查找导航栏中的切换按钮
        const toggle = document.getElementById('toggle-track') || 
                      document.querySelector('.sidebar-nav #toggle-track') ||
                      document.querySelector('.theme-toggle-top #toggle-track');
        
        if (toggle) {
            toggle.onclick = toggleTheme;
            toggle.style.cursor = 'pointer';
            
            // 关键：同步当前主题状态到按钮
            const currentTheme = getCurrentTheme();
            toggle.classList.toggle('dark-mode', currentTheme === 'dark');
            
            console.log('主题切换按钮已绑定，当前主题：' + currentTheme);
        } else {
            console.log('未找到主题切换按钮');
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
    
})();