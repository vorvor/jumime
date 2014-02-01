// We define a function that takes one parameter named $.
(function ($) {
    $(document).ready(function() {
        
        //default
      default_time = $.cookie('jumime_time');
      if (default_time == null) {
        $.cookie('jumime_time',10, {path: '/'});
      }
      
      default_sound = $.cookie('jumime_sound');
      if (default_sound == null) {
        $.cookie('jumime_sound',1, {path: '/'});
      }  
        
        
      $('.view-choose-music .views-row .views-field-nid').each(function() {
        val = $('.field-content', this).html();
        console.log(val);
        selected = '';
        if (val == $.cookie('jumime_sound')) {
            selected = ' checked';
        }
        $(this).prepend('<div class="choose-music"><input ' + selected + ' type="radio" name="choose-music"><span class="choose-music-label">Choose this</span></div>');
      })
      
      $('.choose-music').each(function() {
        val = $(this).next('.field-content').html();
        $('input',this).attr('value', val);
      });
      
      $('.choose-music input').click(function() {
        $.cookie('jumime_sound',$(this).val(), {path: '/'});
        console.log('cookie set' + $.cookie('jumime_sound'));
      })
      
      for (c=20; c>4; c--) {
        selected = '';
        if (c == $.cookie('jumime_time')) {
            selected = ' checked';
        }
        $('.view-choose-music').prepend('<span class="timer_value"><input ' + selected + ' type="radio" value="' + c + ' ">' + c + '</span>');
      }
      
      
      $('.view-choose-music').prepend('<h2 class="count-back-time-chooser">Count back time(sec)</h2>');
      
      $('.timer_value input').click(function() {
        $.cookie('jumime_time',$(this).val(), {path: '/'});
        console.log('cookie set' + $.cookie('jumime_time'));
      })
      
    /*  
    $('#start_meditation').click(function() {
        $.ajax({
            url: '/ajax',
            dataType: 'json',
            success: function(data) {
                $('#music_node').html(data);
            }
        }, 'json');
      })
    */
    
    var time = $.cookie('jumime_time');
    
    function timer() {
        $('#timer').html(time);
        time--;
        if (time == 0) {
            window.location = '/meditation/' + $.cookie('jumime_sound');
        }
        setTimeout(timer, 1000);
        
    }
    
    $('#start_meditation').click(function() {
      timer();
      $(this).hide();
      $('#timer').show();
      $('#timer-reset a').show();
    })
    
    if ($('body').hasClass('page-meditation')) {
        console.log('TIME' + $.cookie('jumime_time'));
        setTimeout(function() {
          window.location = '/meditation-end';
        },61000);
    }
    
    $('.choose-music').hover(function() {
      $('.choose-music-label',this).show();
    },
    function() {
      $('.choose-music-label',this).hide();
    });
    //
    $('.page-choose-music #page, .page-node-3 #page').prepend('<div id="back-to-home"><a href="/">Back to meditation</a></div>');
    
    $('#views_slideshow_controls_text_previous_tips-block a').html('<');
    $('#views_slideshow_controls_text_next_tips-block a').html('>');
    
    
    
    })
  
}(jQuery));