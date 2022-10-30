let galleryImages = document.querySelectorAll('[data-gallery-img]')

let counter = 0;

function createGalleryDiv() {
  let galleryBox = document.createElement('div')
  galleryBox.setAttribute('data', 'gallery-template')
  galleryBox.classList.add('gallery')
  galleryBox.innerHTML = `<img id='img_preview' src='https://images.unsplash.com/photo-1665521583283-0bb4cedaa2e1?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=688&q=80' />
  <div class='gallery__controls'>
    <button id='close__btn'  class='controls__btn__close'>
      <svg width="42" height="42" fill="none" stroke="#ffffff" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
        <path d="M18 6 6 18"></path>
        <path d="m6 6 12 12"></path>
      </svg>
    </button>
    <button id='prev__btn' class='control__btn'>
      <svg width="42" height="42" fill="none" stroke="#ffffff" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
        <path d="M19 12H5"></path>
        <path d="m12 19-7-7 7-7"></path>
      </svg>
    </button>
    <button id='next__btn' class='control__btn'>
      <svg width="42" height="42" fill="none" stroke="#ffffff" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
        <path d="M5 12h14"></path>
        <path d="m12 5 7 7-7 7"></path>
      </svg>
    </button>
  </div>`;
  document.querySelector('body').append(galleryBox)

}

galleryImages.forEach((img, index, arr) => {
  img.addEventListener('click', function() {
    createGalleryDiv()
    let gallery = document.querySelector('.gallery')
    gallery.addEventListener('fullscreenchange', function() {
      if (!document.fullscreenElement) {
        gallery.remove()
      }
    })
    let imgPreview = gallery.querySelector("#img_preview");
    let nextBtn = gallery.querySelector('#next__btn')
    let prevBtn = gallery.querySelector('#prev__btn')
    let closeBtn=gallery.querySelector('#close__btn')
    
    imgPreview.addEventListener('animationend',function(){
      this.classList.remove('fade')
    })
    
    closeBtn.addEventListener('click',function(){
     document.exitFullscreen().then(()=>gallery.remove())
    })
    prevBtn.addEventListener('click', function() {
      imgPreview.classList.add('fade')
      if (counter == 0) {
        counter = arr.length - 1
      }else{
      counter--;
      }
      imgPreview.src = galleryImages[counter].src
    })
    nextBtn.addEventListener('click', function() {
        imgPreview.classList.add('fade')
      if (counter < arr.length - 1) {
        counter++
      } else {
        counter = 0
      }
      imgPreview.src = galleryImages[counter].src
    })
    counter = index;
    imgPreview.src = this.src;
    gallery.requestFullscreen().then(() => {
      gallery.style.display = 'block'
    })
  })
})
