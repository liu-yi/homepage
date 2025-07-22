// Publications page search functionality
(function() {
    'use strict';
    
    let initialized = false;
    
    function initializeSearch() {
        if (initialized) return;
        
        try {
            const searchInput = document.getElementById('pubSearch');
            const filterBtns = document.querySelectorAll('.filter-btn');
            const papers = Array.from(document.querySelectorAll('.markdown-section li'));
            const statNumbers = document.querySelectorAll('.stats-bar .stat-number');
            
            // 确保所有必要元素都存在
            if (!searchInput || !filterBtns.length || !papers.length) {
                console.warn('Publications search: Required elements not found');
                return;
            }
            
            initialized = true;
            
            // 为每个论文添加类型标识
            papers.forEach((paper) => {
                if (!paper.dataset.type) { // 避免重复处理
                    const text = paper.textContent.toLowerCase();
                    if (text.includes('transactions') || text.includes('journal')) {
                        paper.dataset.type = 'journal';
                    } else if (text.includes('manuscript')) {
                        paper.dataset.type = 'manuscript';
                    } else {
                        paper.dataset.type = 'conference';
                    }
                }
            });
            
            // 更新统计信息
            function updateStats() {
                let refereedCount = 0;
                let manuscriptCount = 0;
                
                papers.forEach(paper => {
                    if (paper.style.display !== 'none') {
                        if (paper.dataset.type === 'manuscript') {
                            manuscriptCount++;
                        } else {
                            refereedCount++;
                        }
                    }
                });
                
                if (statNumbers.length >= 2) {
                    statNumbers[0].textContent = refereedCount;
                    statNumbers[1].textContent = manuscriptCount;
                }
            }
            
            // 搜索功能
            function filterPapers() {
                const searchTerm = searchInput.value.toLowerCase().trim();
                const activeFilter = getActiveFilter();
                
                papers.forEach(paper => {
                    const text = paper.textContent.toLowerCase();
                    const matchesSearch = searchTerm === '' || text.includes(searchTerm);
                    const matchesType = activeFilter === 'all' || paper.dataset.type === activeFilter;
                    
                    paper.style.display = matchesSearch && matchesType ? 'list-item' : 'none';
                });
                
                updateStats();
            }
            
            function getActiveFilter() {
                const activeBtn = document.querySelector('.filter-btn.active');
                return activeBtn ? activeBtn.dataset.filter : 'all';
            }
            
            function handleFilter(e) {
                if (!e.target.classList.contains('filter-btn')) return;
                
                filterBtns.forEach(btn => btn.classList.remove('active'));
                e.target.classList.add('active');
                filterPapers();
            }
            
            // 绑定事件（使用捕获避免重复绑定）
            searchInput.removeEventListener('input', filterPapers);
            searchInput.addEventListener('input', filterPapers);
            
            filterBtns.forEach(btn => {
                btn.removeEventListener('click', handleFilter);
                btn.addEventListener('click', handleFilter);
            });
            
            // 初始统计
            updateStats();
            
            console.log('Publications search initialized successfully');
            
        } catch (error) {
            console.error('Error initializing publications search:', error);
        }
    }
    
    // 更可靠的初始化策略
    function initWithRetry() {
        if (initialized) return;
        
        const maxRetries = 10;
        let retries = 0;
        
        function attempt() {
            if (initialized) return;
            
            const searchInput = document.getElementById('pubSearch');
            const papers = document.querySelectorAll('.markdown-section li');
            
            if (searchInput && papers.length > 0) {
                initializeSearch();
            } else if (retries < maxRetries) {
                retries++;
                setTimeout(attempt, 200 * retries); // 指数退避
            } else {
                console.warn('Publications search: Max retries reached, giving up');
            }
        }
        
        attempt();
    }
    
    // 使用Docsify插件系统（更可靠的实现）
    function setupDocsifyPlugin() {
        if (!window.$docsify) {
            window.$docsify = {};
        }
        
        if (!window.$docsify.plugins) {
            window.$docsify.plugins = [];
        }
        
        window.$docsify.plugins.push(function(hook) {
            hook.doneEach(function() {
                // 确保在DOM更新后执行
                setTimeout(initializeSearch, 50);
            });
            
            hook.ready(function() {
                // 最终保险机制
                setTimeout(initializeSearch, 100);
            });
        });
    }
    
    // 主要初始化入口
    function init() {
        if (typeof window.$docsify !== 'undefined') {
            setupDocsifyPlugin();
        } else {
            // 等待Docsify加载
            const observer = new MutationObserver(function() {
                if (window.$docsify && !initialized) {
                    setupDocsifyPlugin();
                    observer.disconnect();
                }
            });
            
            observer.observe(document.body, { childList: true, subtree: true });
            
            // 后备方案：DOMContentLoaded
            document.addEventListener('DOMContentLoaded', function() {
                if (!initialized) {
                    setTimeout(initWithRetry, 500);
                }
            });
            
            // 额外保险
            setTimeout(initWithRetry, 3000);
        }
    }
    
    // 立即开始初始化
    init();
})();