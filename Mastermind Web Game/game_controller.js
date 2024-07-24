let User_Input1 = document.getElementById("User_Input1");
let User_Input2 = document.getElementById("User_Input2");
let User_Input3 = document.getElementById("User_Input3");
let User_Input4 = document.getElementById("User_Input4");
let Submit = document.getElementById("Submit");
let Turn = document.getElementById("Turn");


let Turn1 = document.getElementById("turn1");
let Turn2 = document.getElementById("turn2");
let Turn3 = document.getElementById("turn3");
let Turn4 = document.getElementById("turn4");
let Turn5 = document.getElementById("turn5");
let Turn6 = document.getElementById("turn6");
let Turn7 = document.getElementById("turn7");
let Turn8 = document.getElementById("turn8");
let Turn9 = document.getElementById("turn9");
let Turn10 = document.getElementById("turn10");

let Turn_box = Array(Turn1,Turn2,Turn3,Turn4,Turn5,Turn6,Turn7,Turn8,Turn9,Turn10);

let RT1 = document.getElementById("RT1");
let RT2 = document.getElementById("RT2");
let RT3 = document.getElementById("RT3");
let RT4 = document.getElementById("RT4");
let RT5 = document.getElementById("RT5");
let RT6 = document.getElementById("RT6");
let RT7 = document.getElementById("RT7");
let RT8 = document.getElementById("RT8");
let RT9 = document.getElementById("RT9");
let RT10 = document.getElementById("RT10");

let RTurn_box = Array(RT1,RT2,RT3,RT4,RT5,RT6,RT7,RT8,RT9,RT10);

let Turn_current = 1;
let isClicked = false;

const a = Math.floor(Math.random() * 6);
const b = Math.floor(Math.random() * 6);
const c = Math.floor(Math.random() * 6);
const d = Math.floor(Math.random() * 6);
const SecrectCode = Array(a,b,c,d);

let score = 0;

function Click() {
 

     if(User_Input1.value != "7" && User_Input2.value != "7" && User_Input3.value !="7" && User_Input4.value !="7" ){
    if(Turn_current<11 || score !=4)
    {
   
    isClicked = true;

    let p1 = parseInt(User_Input1.value);
    let p2 = parseInt(User_Input2.value);
    let p3 = parseInt(User_Input3.value);
    let p4 = parseInt(User_Input4.value);

  
    console.log("P1: ", p1);
    console.log("P2: ", p2);
    console.log("P3: ", p3);
    console.log("P4: ", p4);
    console.log("isClicked: ", isClicked);
    score = check_position(Turn_current,p1,p2,p3,p4);

    color_code(Turn_current,p1,p2,p3,p4);


 
      User_Input1.selectedIndex = 0;
      User_Input2.selectedIndex = 0;
      User_Input3.selectedIndex = 0;
      User_Input4.selectedIndex = 0;

      Turn_current++;
      
        if(Turn_current <=10){
    Turn.textContent = `Turn ${Turn_current}`;
    console.log(`Turn ${Turn_current}`);
        }

        if(score == 4){
            alert("You win");
        }

    }
    else
    {
        alert("Lose")
        Turn_current = 1;
        Turn.textContent = `Turn ${Turn_current}`;
        Refresh();
    }
}
else{
    alert("Pls choose color");
}
 
  
}

function color_code(turn,p1,p2,p3,p4){

   let Box = Turn_box[turn-1].children;

   let P1 = Box[1];
   let P2 = Box[2];
   let P3 = Box[3];
   let P4 = Box[4];

   P1.setAttribute("bgcolor",decode(p1));
   P2.setAttribute("bgcolor",decode(p2));
   P3.setAttribute("bgcolor",decode(p3));
   P4.setAttribute("bgcolor",decode(p4));
 
  
}

function decode(code){
   switch(code){
    case 1: return "red"
    case 2: return "green"
    case 3: return "blue"
    case 4: return "yellow"
    case 5: return "brown"
    case 6: return "black"
   }
}

function Refresh(){
    location.reload();
}

function check_position(turn,p1,p2,p3,p4){

    
    let red=0;
    let white=0;

    let Parray = Array(p1,p2,p3,p4);
    let SecrectCode_array = Array((a+1),(b+1),(c+1),(d+1));

    let ArrayOfAns = Array(0,0,0,0);

   for (let i = 0; i < Parray.length; i++) {

        if(Parray[i] == SecrectCode_array[i]){
            ArrayOfAns[i] = 1;
        }
    }

    for (let i = 0; i < Parray.length; i++) {
        if(ArrayOfAns[i] == 1){
            red++;
        }
    }

    for (let i = 0; i < Parray.length; i++) {
        for (let j = 0; j < Parray.length; j++) {
           if(ArrayOfAns[i]==1)
           break;
        else{
            if(Parray[i]==SecrectCode_array[j] && ArrayOfAns[j]!=1)
            ArrayOfAns[i] = 2;
        }
        }   
    }


    for (let i = 0; i < Parray.length; i++) {
      if(ArrayOfAns[i] == 2){
            white++;
        }
    }

    

    let s = red;
    let Box = RTurn_box[turn-1].children;
    let B1 = Box[0];
    let B2 = Box[1];
    let B3 = Box[2];
    let B4 = Box[3];

    let BOX_B = Array(B1,B2,B3,B4);

    for (let i = 0; i < Parray.length; i++) {
        if(red != 0){
            BOX_B[i].setAttribute("bgcolor","black");
            red--;
        }
        else if(white != 0){
            BOX_B[i].setAttribute("bgcolor","red");
            white--;
        }
    }
 
    return s;

   

}


console.log(a+1);
console.log(b+1);
console.log(c+1);
console.log(d+1);


