// Docsify 插件：头像点击波纹效果
(function() {
    'use strict';
    
    // 创建波纹元素的函数
    function createRipple(event) {
        const avatar = event.currentTarget;
        const circle = document.createElement("span");
        const diameter = Math.max(avatar.clientWidth, avatar.clientHeight);
        const radius = diameter / 2;
        
        // 设置波纹样式
        circle.style.width = circle.style.height = `${diameter}px`;
        circle.style.left = `${event.clientX - avatar.getBoundingClientRect().left - radius}px`;
        circle.style.top = `${event.clientY - avatar.getBoundingClientRect().top - radius}px`;
        circle.classList.add("ripple");
        
        // 移除已存在的波纹
        const ripple = avatar.getElementsByClassName("ripple")[0];
        if (ripple) {
            ripple.remove();
        }
        
        avatar.appendChild(circle);
        
        // 波纹动画结束后移除元素
        setTimeout(() => {
            circle.remove();
        }, 600); // 与CSS动画时长保持一致
    }
    
    // 添加CSS样式
    function addRippleStyles() {
        const styleId = 'avatar-ripple-styles';
        if (document.getElementById(styleId)) return; // 避免重复添加
        
        const style = document.createElement('style');
        style.id = styleId;
        style.textContent = `
            #avatar {
                position: relative;
                overflow: hidden;
                border-radius: 50%; /* 确保波纹在圆形内 */
            }
            
            .ripple {
                position: absolute;
                border-radius: 50%;
                background-color: rgba(255, 255, 255, 0.7);
                transform: scale(0);
                animation: ripple-animation 0.6s linear;
                pointer-events: none;
            }
            
            @keyframes ripple-animation {
                to {
                    transform: scale(2.5);
                    opacity: 0;
                }
            }
            
            /* 暗黑模式下的波纹颜色 */
            [data-theme="dark"] .ripple {
                background-color: rgba(200, 200, 200, 0.4);
            }
        `;
        document.head.appendChild(style);
    }
    
    // 插件安装函数
    function install(hook, vm) {
        // 在文档挂载后添加样式
        hook.mounted(function() {
            addRippleStyles();
        });
        
        // 在每次页面渲染完成后绑定事件
        hook.doneEach(function() {
            // 等待Vue渲染完成 (如果使用了Vue)
            setTimeout(() => {
                const avatarElement = document.getElementById('avatar');
                if (avatarElement) {
                    // 移除之前可能添加的事件监听器，避免重复绑定
                    avatarElement.removeEventListener('click', createRipple);
                    avatarElement.addEventListener('click', createRipple);
                }
            }, 150); // 增加延迟确保DOM完全更新
        });
    }
    
    // 将插件添加到 $docsify.plugins 数组中
    $docsify.plugins = [].concat(install, $docsify.plugins);
    
})();