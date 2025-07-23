(function() {
  'use strict';
  
  function toggleAddress() {
    const addressEn = document.getElementById('address-en');
    const addressCn = document.getElementById('address-cn');
    
    if (!addressEn || !addressCn) return;
    
    // 淡入淡出动画
    const fadeOut = (element) => {
      element.style.transition = 'opacity 0.3s ease';
      element.style.opacity = '0';
      setTimeout(() => {
        element.style.display = 'none';
      }, 300);
    };
    
    const fadeIn = (element) => {
      element.style.display = 'block';
      element.style.opacity = '0';
      element.style.transition = 'opacity 0.3s ease';
      setTimeout(() => {
        element.style.opacity = '1';
      }, 10);
    };
    
    if (addressEn.style.display === 'none') {
      fadeOut(addressCn);
      setTimeout(() => fadeIn(addressEn), 300);
    } else {
      fadeOut(addressEn);
      setTimeout(() => fadeIn(addressCn), 300);
    }
  }
  
  function initAddressToggle() {
    const addressEn = document.getElementById('address-en');
    const addressCn = document.getElementById('address-cn');
    
    if (addressEn && addressCn) {
      // 设置初始透明度
      addressEn.style.opacity = '1';
      addressCn.style.opacity = '1';
      
      addressEn.addEventListener('click', toggleAddress);
      addressCn.addEventListener('click', toggleAddress);
    }
  }
  
  // 立即执行
  initAddressToggle();
  
  // 监听docsify的页面加载事件
  if (window.$docsify) {
    window.$docsify.plugins = [].concat(window.$docsify.plugins || [], function(hook) {
      hook.doneEach(function() {
        setTimeout(initAddressToggle, 100);
      });
      hook.ready(function() {
        setTimeout(initAddressToggle, 100);
      });
    });
  } else {
    document.addEventListener('DOMContentLoaded', initAddressToggle);
  }
})();