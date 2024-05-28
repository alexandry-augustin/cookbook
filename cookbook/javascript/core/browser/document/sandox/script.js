function create_text()
{
    // create simple text
    const text = document.createTextNode("Text");
    document.body.appendChild(text);
}

function create_textbox()
{
    let textbox = document.createElement("INPUT");
    //textbox.setAttribute("type", "text");
    textbox.type = "text"; 
    textbox.value = "Type here...";

    document.body.appendChild(textbox);
}

function create_h1(text)
{
    // create h1 element
    const heading = document.createElement("h1");
    heading.innerText = text;
    document.body.appendChild(heading);

    return heading
}

function create_button()
{
    let btn = document.createElement("BUTTON");
    btn.innerHTML = "ok";
    document.body.appendChild(btn);
}

function create_paragraph(text)
{
    let para = document.createElement("P");
    para.innerText = text;
    document.body.appendChild(para);

    return para;
}

function create_link()
{
      let a = document.createElement('a');
      let linkText = document.createTextNode("link text");
      a.appendChild(linkText);
      a.title = "my title text";
      a.href = "http://example.com";
      document.body.appendChild(a);
}

function create_h1_and_text(text)
{
    // create h1 element with text
    const heading = document.createElement("h1");
    const heading_text = document.createTextNode(text);

    heading.appendChild(heading_text);
    document.body.appendChild(heading);
}

function create_div()
{
    const div = document.createElement("div");
    document.body.appendChild(div);

    return div;
}

function create_img(url, id)
{
    let img = document.createElement("img");
    img.id = id
    img.src = url
    document.body.appendChild(img);

    return img;
}

function create_list()
{

    div = create_div()

    let ul = document.createElement('ul');
    div.appendChild(ul);

    function render(element, index, arr)
    {
        let li = document.createElement('li');
        //li.setAttribute('class', 'list_class');
        li.className = 'list_class';

        ul.appendChild(li);

        li.innerHTML=li.innerHTML + element;
    }

    items = ['first','second'];
    items.forEach(render);
}

function create_table()
{
}

//--------------------------------------------------------

function create_elements()
{

    create_textbox()

    heading = create_h1("This is a Header")
    heading.id = "first_header_id"

    create_link()

    create_h1("Header")

    create_paragraph("some text...")

    create_list()

    img = create_img("js.png", "img_id");
    img.width = 100
}

window.onload = function()
{
    // console.dir(document);
    // console.dir(document.all); // array of all DOM elements
    
    // console.dir(document.URL);
    // console.dir(document.domain);
    
    // console.dir(document.head);
    // console.dir(document.body);
    
    document.title = "New Title";
    document.body.bgColor = "00ff00"; // <body bgcolor="ffffff">

    create_elements()
    
    // change element by id
    let first_header = document.getElementById("first_header_id");
    first_header.textContent = "Changed Title";
    first_header.innerText = "Changed Title Again";
    first_header.innerHTML = "<a href='#'>Hey</a>";
    
    // getElementsByClassName()
    let list_class_items = document.getElementsByClassName('list_class');
    // console.dir(items.length);
    for(let i = 0; i < items.length; i++)
    	str = items[i].innerText;
    //	console.log(str)
    //	items[i].innerText = items[i].innerText + '*'
    
    // getElementByTagName()
    let li_items = document.getElementsByTagName('li');
    
    // querySelector()
    let first_header_ = document.querySelector('#first_header_id');
    first_header_.textContent = "Changed Title using querySelector";
    
    let first_item = document.querySelector('.list_class');
    // console.log(first_item);
    
    // querySelectorAll()
    let items_= document.querySelectorAll('.list_class');
    // console.log(items_);
}

// window.onload = function()
// {
//     // run this function when the document is loaded
// 
//     create_text()    
//     create_textbox()
//     create_h1("This is a Header")
//     create_button()
//     create_paragraph("This is a paragraph")
//     create_link()
//    
// }

//--------------------------------------------------------

//https://www.valentinog.com/blog/html-table/

// let mountains = [
//   { name: "Monte Falco", height: 1658, place: "Parco Foreste Casentinesi" },
//   { name: "Monte Falterona", height: 1654, place: "Parco Foreste Casentinesi" },
//   { name: "Poggio Scali", height: 1520, place: "Parco Foreste Casentinesi" },
//   { name: "Pratomagno", height: 1592, place: "Parco Foreste Casentinesi" },
//   { name: "Monte Amiata", height: 1738, place: "Siena" }
// ];
// 
// function generateTableHead(table, data) {
//     let thead = table.createTHead();
//     let row = thead.insertRow();
//     for(let key of data) {
//         let th = document.createElement("th");
//         let text = document.createTextNode(key);
//         th.appendChild(text);
//         row.appendChild(th);
//     }
// }
// 
// function generateTable(table, data) {
//   for(let element of data) {
//     let row = table.insertRow();
//     for(key in element) {
//       let cell = row.insertCell();
//       let text = document.createTextNode(element[key]);
//       cell.appendChild(text);
//     }
//   }
// }
// 
// const table = document.createElement("table");
// document.body.appendChild(table);
// 
// let data = Object.keys(mountains[0]);
// generateTable(table, mountains);
// generateTableHead(table, data);

//--------------------------------------------------------
const table = document.createElement('table');
table.setAttribute('border', '1');
table.style.marginLeft = 'auto';
table.style.marginRight = 'auto';
document.body.appendChild(table);


let header_labels = ['index', 'col1', 'col2']
let header = table.createTHead();
let row = header.insertRow(-1); // appended as the last row
let j=0;
for(const v of header_labels)
{
    let cell = row.insertCell(j++);
    cell.innerHTML = v;
}

function append_row(table, values)
{
    let row = table.insertRow(-1); // appended as the last row

    let j=0;
    for(const v of values)
    {
        let cell = row.insertCell(j++);
        cell.innerHTML = v;
    }
}

let i;
for(i = 0; i < 3; i++)
{
    let values = [i, 'N/A', 'N/A']
    append_row(table, values)
} 




//// https://redstapler.co/load-image-to-canvas-javascript/
//let canvas = document.createElement("canvas");
//context = canvas.getContext('2d');
//let img1 = new Image();
//img1.onload = function()
//{
//  //continue canvas procesing after image has been loaded
//};
//img1.src = document.getElementById("image1").src;
//img1.onload = function()
//{
//      c.width = img1.width;
//      c.height = img1.height;
//      ctx.drawImage(img1, 0, 0);
//}
//// newImg.src = 'img.png';


