# Test

<div id="logo">
      <div id="logo" style="text-align: center">
        <img
          @click="gototodo"
          style="border-radius: 50%; width: calc(30vh)"
          v-on="{ mouseenter: mouseEnter, mouseleave: mouseLeave }"
          :src="logo_list[here_logo]"
        />
      </div>
</div>


  
  <script>
    const { createApp } = Vue
    
    createApp({
      data() {
        return {
          logo_list: ["_media/logo.jpg", "_media/logo2.jpg"],
          hover_avatar: false,
          message: 'hello'
        }
      },
      methods: {
      mouseEnter(event) {
        // console.log(event)
        this.hover_avatar = true;
      },
      mouseLeave(event) {
        // console.log(event)
        this.hover_avatar = false;
      },
    },
    computed: {
      here_logo() {
        if (this.hover_avatar) {
          return 1;
        } else {
          return 0;
        }
      },
    },
    }).mount('#logo')
  </script>