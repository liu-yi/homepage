// Publications page search functionality
(function() {
    'use strict';
    
    function initializeSearch() {
        console.log('Initializing publications search...');
        
        try {
            const searchInput = document.getElementById('pubSearch');
            const filterBtns = document.querySelectorAll('.filter-btn');
            
            // 查找所有论文条目
            const allLis = Array.from(document.querySelectorAll('.markdown-section li'));
            const papers = allLis.filter(li => 
                li.textContent.includes('**') || li.querySelector('.pub-type')
            );
            
            const statNumbers = document.querySelectorAll('.stats-bar .stat-number');
            
            console.log('Found:', {
                searchInput: !!searchInput,
                filterBtns: filterBtns.length,
                papers: papers.length,
                statNumbers: statNumbers.length
            });
            
            if (!searchInput || !filterBtns.length || !papers.length) {
                console.warn('Required elements not found');
                return;
            }
            
            // 为每个论文添加类型标识
            papers.forEach((paper) => {
                if (!paper.dataset.type) {
                    const text = paper.textContent.toLowerCase();
                    const pubTypeEl = paper.querySelector('.pub-type');
                    
                    if (pubTypeEl) {
                        const typeText = pubTypeEl.textContent.toLowerCase();
                        if (typeText.includes('journal')) paper.dataset.type = 'journal';
                        else if (typeText.includes('manuscript')) paper.dataset.type = 'manuscript';
                        else paper.dataset.type = 'conference';
                    } else {
                        if (text.includes('transactions') || text.includes('journal')) {
                            paper.dataset.type = 'journal';
                        } else if (text.includes('manuscript')) {
                            paper.dataset.type = 'manuscript';
                        } else {
                            paper.dataset.type = 'conference';
                        }
                    }
                }
            });
            
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
            
            updateStats();
            console.log('Publications search initialized successfully');
            
        } catch (error) {
            console.error('Error initializing publications search:', error);
        }
    }
    
    // 更可靠的初始化策略
    function initWithRetry() {
        const maxRetries = 10;
        let retries = 0;
        
        function attempt() {
            const searchInput = document.getElementById('pubSearch');
            const papers = document.querySelectorAll('.markdown-section li');
            
            if (searchInput && papers.length > 0) {
                initializeSearch();
            } else if (retries < maxRetries) {
                retries++;
                setTimeout(attempt, 200 * retries);
            }
        }
        
        attempt();
    }
    
    // 检查是否在publications页面
    function isPublicationsPage() {
        const currentPath = window.location.hash;
        return currentPath.includes('publications');
    }
    
    // 仅在publications页面初始化
    function initIfPublications() {
        if (isPublicationsPage()) {
            setTimeout(initWithRetry, 300);
        }
    }
    
    // 监听hash变化
    function watchHashChanges() {
        let lastHash = window.location.hash;
        
        function checkHash() {
            if (window.location.hash !== lastHash) {
                lastHash = window.location.hash;
                
                if (isPublicationsPage()) {
                    setTimeout(initWithRetry, 300);
                }
            }
        }
        
        setInterval(checkHash, 500);
    }
    
    // 初始化
    function init() {
        // 等待Docsify加载完成
        if (document.readyState === 'loading') {
            document.addEventListener('DOMContentLoaded', initIfPublications);
        } else {
            initIfPublications();
        }
        
        // 监听页面变化
        watchHashChanges();
        
        // 后备方案
        setTimeout(initIfPublications, 1000);
    }
    
    init();
})();