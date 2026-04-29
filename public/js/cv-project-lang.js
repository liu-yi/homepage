(function () {
  'use strict';

  function setCardLang(card, lang, toggleSelector) {
    var toggle = card.querySelector(toggleSelector);
    if (!toggle) return;

    var nodes = card.querySelectorAll('.cv-lang[data-en][data-zh]');

    // 清理之前的状态
    window.clearTimeout(card._cvLangTimer);
    if (card._cvHeightEnd) {
      card.removeEventListener('transitionend', card._cvHeightEnd);
      card._cvHeightEnd = null;
    }

    // 在fade out前记录当前高度（auto状态下的精确值）
    var oldHeight = card.getBoundingClientRect().height;

    // 开始fade out
    card.classList.add('cv-lang-fading');

    card._cvLangTimer = window.setTimeout(function () {
      // 更新文本（此时opacity≈0，用户看不到）
      nodes.forEach(function (node) {
        node.textContent = node.getAttribute(lang === 'zh' ? 'data-zh' : 'data-en');
      });
      toggle.setAttribute('data-lang-state', lang);
      toggle.setAttribute('aria-pressed', lang === 'zh' ? 'true' : 'false');

      var thumb = toggle.querySelector('.cv-toggle-thumb');
      if (thumb) {
        thumb.textContent = lang === 'zh' ? '中文' : 'EN';
      }

      // 在auto状态下测量新高度（精确值，包含border）
      var newHeight = card.getBoundingClientRect().height;
      var delta = Math.abs(newHeight - oldHeight);

      if (delta > 0.5) {
        // 先固定为旧高度
        card.style.height = oldHeight + 'px';

        // 双rAF确保跨帧触发CSS transition
        requestAnimationFrame(function () {
          requestAnimationFrame(function () {
            card.style.height = newHeight + 'px';
            card.classList.remove('cv-lang-fading');

            card._cvHeightEnd = function (e) {
              if (e.propertyName === 'height') {
                card.removeEventListener('transitionend', card._cvHeightEnd);
                card._cvHeightEnd = null;
                card.style.height = '';
              }
            };
            card.addEventListener('transitionend', card._cvHeightEnd);
          });
        });
      } else {
        // 高度几乎没变，直接恢复
        card.classList.remove('cv-lang-fading');
        card.style.height = '';
      }
    }, 150);
  }

  function initCard(card, toggleSelector) {
    if (!card || card.getAttribute('data-lang-init') === '1') return;
    card.setAttribute('data-lang-init', '1');

    var toggle = card.querySelector(toggleSelector);
    if (!toggle) return;

    toggle.addEventListener('click', function () {
      var current = toggle.getAttribute('data-lang-state') || 'en';
      var next = current === 'zh' ? 'en' : 'zh';
      setCardLang(card, next, toggleSelector);
    });

    setCardLang(card, 'en', toggleSelector);
  }

  function initAll() {
    var projectCards = document.querySelectorAll('.cv-project-card');
    projectCards.forEach(function (card) {
      initCard(card, '.cv-project-lang-toggle');
    });

    var locationCards = document.querySelectorAll('.cv-location-card');
    locationCards.forEach(function (card) {
      initCard(card, '.cv-location-lang-toggle');
    });
  }

  function registerPlugin() {
    window.$docsify = window.$docsify || {};
    window.$docsify.plugins = [].concat(window.$docsify.plugins || [], function (hook) {
      hook.ready(function () {
        setTimeout(initAll, 0);
      });
      hook.doneEach(function () {
        setTimeout(initAll, 0);
      });
    });
  }

  registerPlugin();

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initAll);
  } else {
    initAll();
  }
})();
