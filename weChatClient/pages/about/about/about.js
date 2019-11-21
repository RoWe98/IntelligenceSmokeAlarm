const app = getApp();
Page({
  data: {
    //StatusBar: app.globalData.StatusBar,
    //CustomBar: app.globalData.CustomBar,
    //ColorList: app.globalData.ColorList,
  },
  onLoad: function () { },
  pageBack() {
    wx.navigateBack({
      delta: 1
    });
  },
  NavChange: function(event){
    wx.redirectTo({
      url: '/pages/my/my',
    })
  }
});
