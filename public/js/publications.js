console.log('Publications.js loaded successfully!');

// 简单的DOMContentLoaded事件监听
document.addEventListener('DOMContentLoaded', function() {
    console.log('DOMContentLoaded fired');
    setTimeout(function() {
        initializeSearch();
    }, 1000); // 给Docsify一些时间来渲染内容
});

function initializeSearch() {
    console.log('Initializing search...');
    const searchInput = document.getElementById('pubSearch');
    const filterBtns = document.querySelectorAll('.filter-btn');
    console.log('Search input found:', searchInput);
    console.log('Filter buttons found:', filterBtns.length);
    
    if (!searchInput) {
        console.log('Search input not found, retrying...');
        setTimeout(initializeSearch, 500);
        return;
    }
    
    // 获取所有论文
    const papers = Array.from(document.querySelectorAll('.markdown-section li'));
    console.log('Papers found:', papers.length);
    
    if (papers.length === 0) {
        console.log('No papers found, retrying...');
        setTimeout(initializeSearch, 500);
        return;
    }
    
    // 为每个论文添加类型标识
    papers.forEach((paper, index) => {
        const text = paper.textContent.toLowerCase();
        if (text.includes('transactions') || text.includes('journal')) {
            paper.dataset.type = 'journal';
        } else if (text.includes('manuscript')) {
            paper.dataset.type = 'manuscript';
        } else {
            paper.dataset.type = 'conference';
        }
    });
    
    // 搜索功能
    function filterPapers() {
        const searchTerm = searchInput.value.toLowerCase();
        const activeFilter = getActiveFilter();
        let visibleRefereedCount = 0;
        let visibleManuscriptCount = 0;
        
        papers.forEach(paper => {
            const text = paper.textContent.toLowerCase();
            const matchesSearch = searchTerm === '' || text.includes(searchTerm);
            const matchesType = activeFilter === 'all' || paper.dataset.type === activeFilter;
            
            const isVisible = matchesSearch && matchesType;
            paper.style.display = isVisible ? 'list-item' : 'none';
            
            if (isVisible) {
                if (paper.dataset.type === 'manuscript') {
                    visibleManuscriptCount++;
                } else {
                    visibleRefereedCount++; // conference or journal (refereed)
                }
            }
        });
        
        // 更新统计信息
        const statNumbers = document.querySelectorAll('.stats-bar .stat-number');
        if (statNumbers.length >= 2) {
            statNumbers[0].textContent = visibleRefereedCount; // Refereed Papers
            statNumbers[1].textContent = visibleManuscriptCount; // Manuscripts
        }
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
    
    console.log('Search initialized successfully with', papers.length, 'papers and', filterBtns.length, 'filter buttons');
}