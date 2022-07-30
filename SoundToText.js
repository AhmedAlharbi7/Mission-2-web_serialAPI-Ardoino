//Author > Ahmed Hajaj
//Build Recognition
var SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
var recognition = new SpeechRecognition();
//Language is Arabic
recognition.lang = 'ar';

//Button start >Start Recognition
click_to_start.addEventListener('click', function () {

    document.getElementById("recording-instructions").innerHTML =
        "Voice recognition activated. Try speaking into the microphone.";

        recognition.start();
});

recognition.addEventListener('result', e => {
     // every single litter joied togother then print it to the textarea
    var transcript = e.results[0][0].transcript;
    //this will print the word in specific format 
    document.getElementById("convert_text").innerHTML = transcript;

    console.log(transcript);
});
//if the user done speaking
recognition.onspeechend = function () {
    document.getElementById("recording-instructions").innerHTML =
        "Voice recognition end. click start to speak again";
}
//if no speech detected
recognition.onerror = function (event) {
    if (event.error == 'no-speech') {
        document.getElementById("recording-instructions").innerHTML =
            "No speech was detected. click start to speak again";
    };
}
