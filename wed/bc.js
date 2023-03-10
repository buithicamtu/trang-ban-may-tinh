const popup = document.querySelector('.chat-popup');
const chatBtn = document.querySelector('.chat-btn');
const submitBtn = document.querySelector('.submit');
const chatArea = document.querySelector('.chat-area');
const inputElm = document.querySelector('input');
const emojiBtn = document.querySelector('#emoji-btn');
const picker = new EmojiButton();


// Emoji selection  
window.addEventListener('DOMContentLoaded', () => {

    picker.on('emoji', emoji => {
      document.querySelector('input').value += emoji;
    });
  
    emojiBtn.addEventListener('click', () => {
      picker.togglePicker(emojiBtn);
    });
  });        

//   chat button toggler 

chatBtn.addEventListener('click', ()=>{
    popup.classList.toggle('show');
})

// send 
submitBtn.addEventListener('click', ()=>{
    let userInput = inputElm.value;

    let temp = `<div class="out-msg">
    <span class="my-msg">${userInput}</span>
    <img src="uploads/2.png" class="avatar">
    </div>`;

    chatArea.insertAdjacentHTML("beforeend", temp);
    inputElm.value = '';

})



//back to top
$(window).scroll(function(){
if ($(this).scrollTop()!=0){
  $('#bttop').show();
}
else{
  $('#bttop').hide();
}
});

$('#bttop').click(function(){
  $('html').animate({
scrollTop:0
  },500);
});