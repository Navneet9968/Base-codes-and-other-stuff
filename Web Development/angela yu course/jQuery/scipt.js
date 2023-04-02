// $("h1").css("color", "red ");  //two value so we are setting the value
console.log($("h1").css("font-size"));  //one value in css brackets the we are setting the value


//adding the class 
$("h1").addClass("h1-fancy");

//removing the class
// $("h1").removeClass("h1-fancy");

//checking if it has class
console.log($("h1").hasClass("h1-fancy"));


// ---------------------------------Manipulating text with jQuery---------------------------

// first we have to select the thing of which html/text we want to change by $ 
//then we can use .text("  ") or .html() to change the value

$("button").text("Don't click me!");                                //manipulating text with jQuery
$("button").html("<em><strong>Don't click me!</strong></em>");      //manipulating all html of every match with jQuery


// ---------------------------------Manipulating attributes with jQuery---------------------------

// this is similar to css part as if we specify only one value then it will get that value
//but if we specify two values then it will set the second value in first value

$("a").attr("href","https://google.com");  //changing the attribute 
console.log($("a").attr("href"));           //getting the attribute
console.log($("h1").attr("class"));         //since class is also an attribute we can get and set classes using attr also
// $("h1").attr("class","");


// ---------------------------------Adding Event Listeners---------------------------
//first selecting the object then function    //however it will apply it to all buttons
$("button").click(function() {
    $("h1").css("color","#000000");
});

$(document).keypress(function (event) {
    console.log(event.key);
    $("h1").text(event.key);
});
var original=$("h1").css("color");
$("h1").on("mouseover",function(){
    $("h1").css("color","red");
});
$("h1").on("mouseleave",function(){
    $("h1").css("color",original);
});


//-------------------------------- creating html elements on the fly--------------------------------

//first select the object using $ then use .before("html code");   to make the element before the object and .after () for after the object
//as a separeate element

$("h1").after("<button>New</button>");
// there is also .prepend() and .append() to add just before and after the content within the same element

// deleting
// $("button").remove();


   





