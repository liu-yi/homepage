(function () {
  'use strict';

  function setCardLang(card, lang, toggleSelector) {
    var toggle = card.querySelector(toggleSelector);
    if (!toggle) return;

    var nodes = card.querySelectorAll('.cv-lang[data-en][data-zh]');
    card.classList.add('cv-lang-fading');

    window.clearTimeout(card._cvLangTimer);
    card._cvLangTimer = window.setTimeout(function () {
      nodes.forEach(function (node) {
        node.textContent = node.getAttribute(lang === 'zh' ? 'data-zh' : 'data-en');
      });
      toggle.setAttribute('data-lang-state', lang);
      toggle.setAttribute('aria-pressed', lang === 'zh' ? 'true' : 'false');

      var thumb = toggle.querySelector('.cv-toggle-thumb');
      if (thumb) {
        thumb.textContent = lang === 'zh' ? '中文' : 'EN';
      }

      card.classList.remove('cv-lang-fading');
    }, 120);
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
