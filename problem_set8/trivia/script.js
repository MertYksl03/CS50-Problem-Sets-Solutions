let correct = document.querySelector("#correct");
let incorrect = document.getElementsByClassName("js-incorrect-answer");
let status = document.querySelector("#status");

let correctAnswerFound = false;


correct.onclick = function() {
    if(!correctAnswerFound) {
        correct.style.backgroundColor = 'green';
        status.innerHTML = "Correct!!!!";
        correctAnswerFound = true;
        //make the incorrect answer red
        for (let i = 0; i < incorrect.length; i++) {
            incorrect[i].style.backgroundColor = 'rgb(255, 100, 100)';
        }
    } 
}

for (let i = 0; i < incorrect.length; i++) {
    incorrect[i].onclick = function() {
        incorrect[i].style.backgroundColor = 'red';
        status.innerHTML = "Incorrect :(";
    };
}

let input = document.querySelector("#input");
let status2 = document.querySelector("#status2");

input.addEventListener("keypress", function(event) {
    // If the user presses the "Enter" key on the keyboard
    if (event.key === "Enter") {
      // Cancel the default action, if needed
      event.preventDefault();
      // Trigger the button element with a click
      document.getElementById("submit-button").click();
    }
  });

function checkAnswer() {
    if(input.value.toLowerCase() === "ankara") {
        input.style.backgroundColor = 'green';
        status2.innerHTML = 'Correct!!!';
    } else {
        input.style.backgroundColor = 'red';
        status2.innerHTML = 'Incorrect :(';
    }
    questionAnswered = true;
}



