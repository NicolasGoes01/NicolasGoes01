class Player
{
    name
    money
    flag

    constructor(name, money, flag)
    {
        this.name = name
        this.money = money
        this.flag = flag
    }
}

function Mainscreen()
{
    var mainscreen = document.getElementById('mainscreen')
    var txtvalorInicial = document.getElementById('valorInicial')
    var txtApostaObrigatoria = document.getElementById('apostaObrigatoria')

    if (txtvalorInicial.value.length == 0 || txtApostaObrigatoria.value.length == 0)
    {
        window.alert('Valor inválido! Tente novamente!')
    }
    else
    {
        var content = '<p>Agora digite o nome dos jogadores:</p>'
        var txtqtdPlayers = document.getElementById('qtdPlayers')
        var qtdPlayers = Number(txtqtdPlayers.value)
        var valorInicial = Number(txtvalorInicial.value)
        var apostaObrigatoria = Number(txtApostaObrigatoria.value)
        
        for (var i = 0; i < qtdPlayers; i++)
        {
            content += (`<p><input type="text" name="player${i + 1}" id="player${i + 1}" placeholder="Jogador ${i + 1}"></p>`)
        }
        
        content += `<input type="button" value="Avançar" onclick="createPlayers()">`

        mainscreen.innerHTML = content

        localStorage.setItem('qtdPlayers', qtdPlayers)
        localStorage.setItem('valorInicial', valorInicial)
        localStorage.setItem('apostaObrigatoria', apostaObrigatoria)
    }
}

function printPlayersMoney()
{
    var players = JSON.parse(localStorage.getItem('players'))
    var playersMoney = document.getElementById('playersMoney')
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var playersMoneyContent = '<p id="printPlayersMoney">'

    for (var i = 0; i < qtdPlayers; i++)
    {
        playersMoneyContent += `${players[i].name}:    R$ ${players[i].money}<br>`
    }

    playersMoneyContent += '</p>'
    playersMoney.innerHTML = playersMoneyContent
}

function upBet()
{
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var upBet = document.getElementById('upBet')
    var bettxt = document.getElementById('bet')
    var bet = Number(bettxt.value)
    localStorage.setItem('bet', bet)
    var upBetContent = `<p>Selecione os jogadores que aceitaram a aposta de R$ ${bet}:</p>`

    if (bettxt.value.length == 0)
    {
        window.alert('Valor inválido! Tente novamente!')
    }
    else
    {
        for (var i = 0; i < qtdPlayers; i++)
        {
            if (players[i].flag == 1)
            {
                upBetContent += `<p><label for="p${i}"><input type="checkbox" name="upBet" id="upBet${i}" checked>${players[i].name}</label></p>`
            }
        }

        upBetContent += `<p><input type="button" value="Avançar" onclick="makingBet()"></p>`

        upBet.innerHTML = upBetContent
    }
}

function makingBet()
{
    var totalBet = parseInt(localStorage.getItem('totalBet'))
    var upBet = document.getElementById('upBet')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var bet = parseInt(localStorage.getItem('bet'))
    var upBetContent = '<p>Aposta feita com sucesso!</p>'
    upBetContent += `<p><input type="button" value="Continuar" onclick="window.location.href = 'inGame.html'"></p>`
    
    for (let i = 0; i < qtdPlayers; i++)
    {
        var checkedVerify = document.getElementById(`upBet${i}`)

        if (checkedVerify != null && checkedVerify.checked && players[i].flag == 1)
        {
            if (players[i].money - bet < 0)
            {
                totalBet += players[i].money
                players[i].money = 0
            }
            else
            {
                totalBet += bet
                players[i].money -= bet
            }
        }
        else
        {
            players[i].flag = 0
        }
    }
    
    localStorage.setItem('players', JSON.stringify(players))
    localStorage.setItem('totalBet', totalBet)
    
    upBet.innerHTML = upBetContent
}

function roundEnd()
{
    var roundEnd = document.getElementById('roundEnd')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var roundEndContent = '<p>Vencedor da rodada:</p>'

    if (players[0].flag == 1)
    {
        roundEndContent += `<p><label for="w0"><input type="radio" name="winner" id="winner0" checked>${players[0].name}</label></p>`
    }

    for (var i = 1; i < qtdPlayers; i++)
    {
        if (players[i].flag == 1)
        {
            roundEndContent += `<p><label for="w${i}"><input type="radio" name="winner" id="winner${i}">${players[i].name}</label></p>`
        }
    }

    roundEndContent += `<p><label for="tie"><input type="radio" name="winner" id="tie">Empate</label></p>`
    roundEndContent += `<p><input type="button" value='Avançar' onclick="winner()"></p>`

    roundEnd.innerHTML = roundEndContent
}

function winner()
{
    var totalBet = parseInt(localStorage.getItem('totalBet'))
    var roundEnd = document.getElementById('roundEnd')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var tie = document.getElementById('tie')
    var roundEndContent = ''

    if (tie != null && tie.checked)
    {
        roundEndContent += '<p>Selecione os jogadores que empataram:</p>'

        for (var i = 0; i < qtdPlayers; i++)
        {
            if (players[i].flag == 1)
            {
                roundEndContent += `<p><label for="w${i}"><input type="checkbox" name="ties" id="tie${i}">${players[i].name}</label></p>`
            }
        }

        roundEndContent += `<p><input type="button" value='Avançar' onclick="tie()"></p>`
    }
    else
    {
        for (var i = 0; i < qtdPlayers; i++)
        {
            var winner = document.getElementById(`winner${i}`)
            
            if (winner != null && winner.checked)
            {
                roundEndContent += `<p>O vencedor da rodada é ${players[i].name}.</p>`
                players[i].money += totalBet
            }
        }

        roundEndContent += `<p><input type="button" value='Continuar' onclick="window.location.href = 'game.html'"></p>`

        for (var i = 0; i < qtdPlayers; i++)
        {
            players[i].flag = 0
        }
        totalBet = 0

        localStorage.setItem('players', JSON.stringify(players))
        localStorage.setItem('totalBet', totalBet)

        VerifyAndRemovePlayers()
    }
    
    roundEnd.innerHTML = roundEndContent
}

function tie()
{
    var totalBet = parseInt(localStorage.getItem('totalBet'))
    var roundEnd = document.getElementById('roundEnd')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var roundEndContent = '<p>Valor divido entre os jogadores que empataram!</p>'
    var winnersCounting = 0

    for (var i = 0; i < qtdPlayers; i++)
    {
        var tie = document.getElementById(`tie${i}`)
            
        if (tie != null && tie.checked)
        {
            winnersCounting++
        }
    }

    for (var i = 0; i < qtdPlayers; i++)
    {
        var tie = document.getElementById(`tie${i}`)
            
        if (tie != null && tie.checked)
        {
            players[i].money += totalBet / winnersCounting
        }
    }

    roundEndContent += `<p><input type="button" value='Continuar' onclick="window.location.href = 'game.html'"></p>`

    for (var i = 0; i < qtdPlayers; i++)
    {
        players[i].flag = 0
    }
    totalBet = 0

    localStorage.setItem('players', JSON.stringify(players))
    localStorage.setItem('totalBet', totalBet)

    VerifyAndRemovePlayers()

    roundEnd.innerHTML = roundEndContent
}

function firstRound()
{
    VerifyAndRemovePlayers()

    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var firstRound = document.getElementById('firstRound')
    var firstRoundContent = '<p>Selecione quem foi na primeira rodada:</p>'

    for (var i = 0; i < qtdPlayers; i++)
    {
        firstRoundContent += `<p><label for="p${i}"><input type="checkbox" name="inRound" id="inRound${i}" checked>${players[i].name}</label>`
        firstRoundContent += `<select name="apob${i}" id="apob${i}">`
        firstRoundContent += `<option value="Nada">Nada</option>`
        firstRoundContent += `<option value="Parcial">Parcial</option>`
        firstRoundContent += `<option value="Obrigatória">Obrigatória</option>`
        firstRoundContent += `</select></p>`
    }

    firstRoundContent += `<p><input type="button" value='Avançar' onclick="checkFirstBet()"></p>`

    firstRound.innerHTML = firstRoundContent
}

function checkFirstBet()
{
    var totalBet = 0
    var apostaObrigatoria = parseInt(localStorage.getItem('apostaObrigatoria'))
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')

    for (var i = 0; i < qtdPlayers; i++)
    {
        if (document.getElementById(`inRound${i}`).checked)
        {
            players[i].flag = 1

            if (players[i].money - apostaObrigatoria < 0)
            {
                totalBet += players[i].money
                players[i].money = 0
            }
            else
            {
                totalBet += apostaObrigatoria
                players[i].money -= apostaObrigatoria
            }
        }
        else
        {
            var txtapob = document.getElementById(`apob${i}`)
            var apob = String(txtapob.value)

            if (apob == 'Parcial')
            {
                if (players[i].money - (apostaObrigatoria / 2) < 0)
                {
                    totalBet += players[i].money
                    players[i].money = 0
                }
                else
                {
                    totalBet += apostaObrigatoria / 2
                    players[i].money -= apostaObrigatoria / 2
                }
            }
            else if (apob == 'Obrigatória')
            {
                if (players[i].money - apostaObrigatoria < 0)
                {
                    totalBet += players[i].money
                    players[i].money = 0
                }
                else
                {
                    totalBet += apostaObrigatoria
                    players[i].money -= apostaObrigatoria
                }
            }
        }
    }
    
    localStorage.setItem('players', JSON.stringify(players))
    localStorage.setItem('totalBet', totalBet)

    window.location.href = 'inGame.html'
}

function moreMoney()
{
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var moreMoney = document.getElementById('moreMoney')
    var moreMoneyContent = '<p>Selecione quem receberá mais dinheiro:</p>'

    moreMoneyContent += '<select name="selMoreMoney" id="selMoreMoney">'

    for (let i = 0; i < qtdPlayers; i++)
    {
        moreMoneyContent += `<option value="${players[i].name}">${players[i].name}</option>`
    }

    moreMoneyContent += '</select>'
    moreMoneyContent += `<div><p><input type="text" name='mMoney' id="mMoney" placeholder="Valor a ser adicionado"></p></div>`
    moreMoneyContent += `<div><p><input type="button" value="Avançar" onclick="moreMoneyConfirmation()"></p></div>`

    moreMoney.innerHTML = moreMoneyContent
}

function lessMoney()
{
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var lessMoney = document.getElementById('lessMoney')
    var lessMoneyContent = '<p>Selecione quem perderá dinheiro:</p>'

    lessMoneyContent += '<select name="sellessMoney" id="sellessMoney">'

    for (let i = 0; i < qtdPlayers; i++)
    {
        lessMoneyContent += `<option value="${players[i].name}">${players[i].name}</option>`
    }

    lessMoneyContent += '</select>'
    lessMoneyContent += `<div><p><input type="text" name='lMoney' id="lMoney" placeholder="Valor a ser retirado"></p></div>`
    lessMoneyContent += `<div><p><input type="button" value="Avançar" onclick="lessMoneyConfirmation()"></p></div>`

    lessMoney.innerHTML = lessMoneyContent
}

function moreMoneyConfirmation()
{
    var moreMoney = document.getElementById('moreMoney')
    var txtPlayer = document.getElementById('selMoreMoney')
    var player = String(txtPlayer.value)
    var txtMoney = document.getElementById('mMoney')
    var money = Number(txtMoney.value)
    localStorage.setItem('player', player)
    localStorage.setItem('money', money)

    if (txtMoney.value.length == 0)
    {
        window.alert('Valor inválido! Tente novamente!')
    }
    else
    {
        var moreMoneyConfirmationContent = `<p>Tem certeza que deseja adicionar R$ ${money} ao(à) jogador(a) ${player}?`

        moreMoneyConfirmationContent += `<p><input type="button" value="Sim" onclick="addMoney()"><input type="button" value="Não" onclick="moreMoney()"></p>`

        moreMoney.innerHTML = moreMoneyConfirmationContent
    }
}

function lessMoneyConfirmation()
{
    var lessMoney = document.getElementById('lessMoney')
    var txtPlayer = document.getElementById('sellessMoney')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var currentPlayerIndex
    var player = String(txtPlayer.value)
    var txtMoney = document.getElementById('lMoney')
    var money = Number(txtMoney.value)
    localStorage.setItem('player', player)
    localStorage.setItem('money', money)
    
    if (txtMoney.value.length == 0)
    {
        window.alert('Valor inválido! Tente novamente!')
    }
    else
    {
        for (let i = 0; i < qtdPlayers; i++)
        {
            if (player == players[i].name)
            {
                currentPlayerIndex = i
            }
        }
        if (players[currentPlayerIndex].money - money < 0)
        {
            window.alert(`Jogador não possui esse dinheiro! Tente novamente!`)
        }
        else
        {
            var lessMoneyConfirmationContent = `<p>Tem certeza que deseja retirar R$ ${money} do(a) jogador(a) ${player}?`

            lessMoneyConfirmationContent += `<p><input type="button" value="Sim" onclick="removeMoney()"><input type="button" value="Não" onclick="lessMoney()"></p>`

            lessMoney.innerHTML = lessMoneyConfirmationContent
        }
    }
}

function addMoney()
{
    var moreMoney = document.getElementById('moreMoney')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var player = localStorage.getItem('player')
    var money = parseInt(localStorage.getItem('money'))
    var moreMoneyContent = `<p>Foi adicionado R$ ${money} ao(à) jogador(a) ${player} com sucesso!</p>`

    for (let i = 0; i < qtdPlayers; i++)
    {
        if (player == players[i].name)
        {
            var currentMoney = parseInt(players[i].money)
            currentMoney += money
            players[i].money = currentMoney
        }
    }

    localStorage.setItem('players', JSON.stringify(players))
    
    moreMoneyContent += `<p><input type="button" value="Continuar" onclick="window.location.href = 'game.html'"></p>`

    moreMoney.innerHTML = moreMoneyContent
}

function removeMoney()
{
    var lessMoney = document.getElementById('lessMoney')
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var player = localStorage.getItem('player')
    var money = parseInt(localStorage.getItem('money'))
    var lessMoneyContent = `<p>Foi retirado R$ ${money} do(a) jogador(a) ${player} com sucesso!</p>`

    for (let i = 0; i < qtdPlayers; i++)
    {
        if (player == players[i].name)
        {
            var currentMoney = parseInt(players[i].money)
            currentMoney -= money
            players[i].money = currentMoney
        }
    }

    localStorage.setItem('players', JSON.stringify(players))
    
    lessMoneyContent += `<p><input type="button" value="Continuar" onclick="window.location.href = 'game.html'"></p>`

    lessMoney.innerHTML = lessMoneyContent
}

function createPlayers()
{
    window.location.href = 'game.html'

    var qtdPlayers = localStorage.getItem('qtdPlayers')
    var valorInicial = localStorage.getItem('valorInicial')

    var players = []

    for (let i = 0; i < qtdPlayers; i++)
    {
        var name = String(document.getElementById(`player${i + 1}`).value)
        players[i] = new Player(name, valorInicial, 0)
    }

    localStorage.setItem('players', JSON.stringify(players))
}

function VerifyAndRemovePlayers()
{
    var players = JSON.parse(localStorage.getItem('players'))
    var qtdPlayers = localStorage.getItem('qtdPlayers')

    for (let i = 0; i < qtdPlayers; i++)
    {
        if (players[i].money == 0)
        {
            for (let j = i; j < qtdPlayers; j++)
            {
                players[j] = players[j + 1]
            }

            players[qtdPlayers - 1] = null
            qtdPlayers--
        }
    }

    localStorage.setItem('players', JSON.stringify(players))
    localStorage.setItem('qtdPlayers', qtdPlayers)
}
