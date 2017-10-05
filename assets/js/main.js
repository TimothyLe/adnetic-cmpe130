// Fade in function
var el = document.getElementById("fadein");

function fadeIn(el) {
  el.style.opacity = 0;


  var tick = function() {
    el.style.opacity = +el.style.opacity + 0.01;


    if (+el.style.opacity < 1) {
      (window.requestAnimationFrame && requestAnimationFrame(tick)) || setTimeout(tick, 16)
    }
  };

  tick();
}

fadeIn(el);

// Longer fade in
var el = document.getElementById("fadein2");

function fadeIn(el) {
  el.style.opacity = 0;


  var tick = function() {
    el.style.opacity = +el.style.opacity + 0.01;


    if (+el.style.opacity < 1) {
      (window.requestAnimationFrame && requestAnimationFrame(tick)) || setTimeout(tick, 32)
    }
  };

  tick();
}

fadeIn(el);