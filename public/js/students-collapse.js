// Docsify plugin for collapsible students section
(function() {
  var plugin = function(hook, vm) {
    hook.doneEach(function() {
      // Initialize collapsible functionality after each page load
      initStudentsCollapse();
    });

    function initStudentsCollapse() {
      const toggle = document.querySelector('.students-toggle');
      const content = document.querySelector('.students-content-collapsible');
      
      if (!toggle || !content) return;

      // Set initial state
      toggle.setAttribute('aria-expanded', 'false');
      content.style.maxHeight = '0';
      content.style.overflow = 'hidden';

      // Add click event listener
      toggle.addEventListener('click', function() {
        toggleStudentsSection(this);
      });

      // Add keyboard support
      toggle.addEventListener('keydown', function(e) {
        if (e.key === 'Enter' || e.key === ' ') {
          e.preventDefault();
          toggleStudentsSection(this);
        }
      });
    }

    function toggleStudentsSection(element) {
      const content = element.parentNode.querySelector('.students-content-collapsible');
      const icon = element.querySelector('.students-toggle-icon');
      
      if (!content || !icon) return;

      const isExpanded = element.classList.contains('expanded');
      
      if (isExpanded) {
        // Collapse
        content.style.maxHeight = '0';
        element.classList.remove('expanded');
        icon.style.transform = 'rotate(0deg)';
      } else {
        // Expand
        content.style.maxHeight = content.scrollHeight + 'px';
        element.classList.add('expanded');
        icon.style.transform = 'rotate(180deg)';
      }
      
      element.setAttribute('aria-expanded', !isExpanded);
    }
  };

  // Register as Docsify plugin
  window.$docsify = window.$docsify || {};
  window.$docsify.plugins = window.$docsify.plugins || [];
  window.$docsify.plugins.push(plugin);
})();