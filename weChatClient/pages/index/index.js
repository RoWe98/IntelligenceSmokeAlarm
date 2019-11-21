//index.js
//获取应用实例
const app = getApp()
Page({
  data: {
   PageCur: 'basics',
   img:"/images/tx.png",
   time:"2019-11-20",
   btn:"智能之旅",
    swiperList: [{
      id: 0,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big84000.jpg'
    }, {
      id: 1,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big84001.jpg',
    }, {
      id: 2,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big39000.jpg'
    }, {
      id: 3,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big10001.jpg'
    }, {
      id: 4,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big25011.jpg'
    }, {
      id: 5,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big21016.jpg'
    }, {
      id: 6,
      type: 'image',
      url: 'https://ossweb-img.qq.com/images/lol/web201310/skin/big99008.jpg'
    }],
  },
  start:function(){
    // console.log("点到了");
  //页面跳转：
    wx.redirectTo({
      url: '../my/my',
      // // 成功后的回调函数
      // success: function(res) {},
      // // 失败的回掉函数
      // fail: function(res) {},
      // // 始终执行的回调函数
      // complete: function(res) {},
    })
  },
  NavChange(e) {
    // this.setData({
    //   PageCur: e.currentTarget.dataset.cur
    //})
    wx.redirectTo({
      url: '../my/my',
    })
}
})

