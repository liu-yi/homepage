// Publications page search functionality
(function() {
    'use strict';
    
    let initialized = false;
    
    function initializeSearch() {
        if (initialized) return;
        
        const searchInput = document.getElementById('pubSearch');
        const filterBtns = document.querySelectorAll('.filter-btn');
        const papers = Array.from(document.querySelectorAll('.markdown-section li'));
        const statNumbers = document.querySelectorAll('.stats-bar .stat-number');
        
        if (!searchInput || papers.length === 0) return;
        
        initialized = true;
        
        // 为每个论文添加类型标识
        papers.forEach((paper) => {
            const text = paper.textContent.toLowerCase();
            if (text.includes('transactions') || text.includes('journal')) {
                paper.dataset.type = 'journal';
            } else if (text.includes('manuscript')) {
                paper.dataset.type = 'manuscript';
            } else {
                paper.dataset.type = 'conference';
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
            const searchTerm = searchInput.value.toLowerCase();
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
            filterBtns.forEach(btn => btn.classList.remove('active'));
            e.target.classList.add('active');
            filterPapers();
        }
        
        // 绑定事件
        searchInput.addEventListener('input', filterPapers);
        filterBtns.forEach(btn => btn.addEventListener('click', handleFilter));
        
        // 初始统计
        updateStats();
    }
    
    // 等待内容加载
    function waitForContent() {
        const searchInput = document.getElementById('pubSearch');
        if (searchInput) {
            initializeSearch();
        } else {
            setTimeout(waitForContent, 500);
        }
    }
    
    // 使用Docsify插件系统
    if (window.$docsify && window.$docsify.plugins) {
        window.$docsify.plugins.push(function(hook) {
            hook.doneEach(function() {
                setTimeout(initializeSearch, 100);
            });
        });
    } else {
        // 后备方案
        document.addEventListener('DOMContentLoaded', function() {
            setTimeout(waitForContent, 1000);
        });
    }
})();