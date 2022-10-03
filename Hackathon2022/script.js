function FutOptions()
{
    var futBet = document.getElementById('futbet')
    var newFutBet = '<p id="futbet">FUTEBOL <input type="button" value="⬇️" onclick="FutOptionsBack()"></p>'
    newFutBet += '<span id="opfut11" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="FutOption11()">Brasil</span> x <span id="opfut21" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="FutOption21()">Sérvia</span>'
    newFutBet += '<br><br><span id="opfut12" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="FutOption12()">Camarões</span> x <span id="opfut22" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="FutOption22()">Suíça</span>'

    futBet.innerHTML = newFutBet
}

function FutOptionsBack()
{
    var futBet = document.getElementById('futbet')
    var newFutBet = '<p id="futbet">FUTEBOL <input type="button" value="⬇️" onclick="FutOptions()"></p>'

    futBet.innerHTML = newFutBet
}

function VolOptions()
{
    var volBet = document.getElementById('volbet')
    var newVolBet = '<p id="volbet">VOLEI <input type="button" value="⬇️" onclick="VolOptionsBack()"></p>'
    newVolBet += '<span id="opvol11" style="width: 20%; padding: 5px;   border-radius: 5px;    background-color: white;\n\n" onclick="VolOption11()">Brasil</span> x <span id="opvol21" style="width: 20%; padding: 5px;   border-radius: 5px; background-color: white;" onclick="VolOption21()">Argentina</span>'
    newVolBet += '<br><br><span id="opvol12" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="VolOption12()">EUA</span> x <span id="opvol22" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="VolOption22()">Polônia</span>'

    volBet.innerHTML = newVolBet
}

function VolOptionsBack()
{
    var volBet = document.getElementById('volbet')
    var newVolBet = '<p id="volbet">VOLEI <input type="button" value="⬇️" onclick="VolOptions()"></p>'

    volBet.innerHTML = newVolBet
}

function XadOptions()
{
    var xadBet = document.getElementById('xadbet')
    var newXadBet = '<p id="xadbet">XADREZ <input type="button" value="⬇️" onclick="XadOptionsBack()"></p>'
    newXadBet += '<span id="opxad1" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="XadOption1()">Magnus</span> x <span id="opxad2" style="width: 20%; padding: 5px; border-radius: 5px; background-color: white;" onclick="XadOption2()">Nakamura</span>'

    xadBet.innerHTML = newXadBet
}

function XadOptionsBack()
{
    var xadBet = document.getElementById('xadbet')
    var newXadBet = '<p id="xadbet">XADREZ <input type="button" value="⬇️" onclick="XadOptions()"></p>'

    xadBet.innerHTML = newXadBet
}

function FutOption11()
{
    let op1 = document.getElementById('opfut11')
    let op2 = document.getElementById('opfut21')

    op1.style.backgroundColor = "rgb(58, 190, 58)";
    op2.style.backgroundColor = "white";
}

function FutOption21()
{
    let op1 = document.getElementById('opfut11')
    let op2 = document.getElementById('opfut21')

    op1.style.backgroundColor = "white";
    op2.style.backgroundColor = "rgb(58, 190, 58)";
}

function FutOption12()
{
    let op1 = document.getElementById('opfut12')
    let op2 = document.getElementById('opfut22')

    op1.style.backgroundColor = "rgb(58, 190, 58)";
    op2.style.backgroundColor = "white";
}

function FutOption22()
{
    let op1 = document.getElementById('opfut12')
    let op2 = document.getElementById('opfut22')

    op1.style.backgroundColor = "white";
    op2.style.backgroundColor = "rgb(58, 190, 58)";
}

function VolOption11()
{
    let op1 = document.getElementById('opvol11')
    let op2 = document.getElementById('opvol21')

    op1.style.backgroundColor = "rgb(58, 190, 58)";
    op2.style.backgroundColor = "white";
}

function VolOption21()
{
    let op1 = document.getElementById('opvol11')
    let op2 = document.getElementById('opvol21')

    op1.style.backgroundColor = "white";
    op2.style.backgroundColor = "rgb(58, 190, 58)";
}

function VolOption12()
{
    let op1 = document.getElementById('opvol12')
    let op2 = document.getElementById('opvol22')

    op1.style.backgroundColor = "rgb(58, 190, 58)";
    op2.style.backgroundColor = "white";
}

function VolOption22()
{
    let op1 = document.getElementById('opvol12')
    let op2 = document.getElementById('opvol22')

    op1.style.backgroundColor = "white";
    op2.style.backgroundColor = "rgb(58, 190, 58)";
}

function XadOption1()
{
    let op1 = document.getElementById('opxad1')
    let op2 = document.getElementById('opxad2')

    op1.style.backgroundColor = "rgb(58, 190, 58)";
    op2.style.backgroundColor = "white";
}

function XadOption2()
{
    let op1 = document.getElementById('opxad1')
    let op2 = document.getElementById('opxad2')

    op1.style.backgroundColor = "white";
    op2.style.backgroundColor = "rgb(58, 190, 58)";
}
