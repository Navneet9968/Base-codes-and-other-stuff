document.querySelector("li").lastElementChild.innerHTML="Navneet";
document.querySelector("li a").style.color="red";
document.querySelector("button").style.backgroundColor="black";
document.querySelector("button").style.color="white";
document.querySelector("h1").classList.add("huge");
// document.querySelector("h1").classList.remove("huge");

document.querySelector("h1").innerHTML="<em>Navneet</em>";




function toggleMode(){
    // document.classList.add("dark-mode");
    document.querySelector("body").classList.toggle("dark-mode");
    
    var myText=document.querySelector("button").textContent;

    if(myText=="Dark Mode"){
        document.querySelector("button").textContent="Light Mode";
    }
    else if(myText=="Light Mode"){
        document.querySelector("button").textContent="Dark Mode";
    } 
}

