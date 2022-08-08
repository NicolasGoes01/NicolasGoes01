/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Controler;

import Modelo.*;
import Auxiliar.Posicao;
import java.util.ArrayList;
import java.awt.event.KeyEvent;


public class ControleDeJogo {
    public void desenhaTudo(ArrayList<Elemento> e){
        for(int i = 0; i < e.size(); i++){
            e.get(i).autoDesenho();
        }
    }

    public void processaTudo(Lolo lolo, ArrayList<Elemento> elementos, ArrayList<Elemento> tiro, int lastKeyEvent) {
        Elemento tempBau = null;

        for (int i = 0; i < elementos.size(); i++) {
            if (elementos.get(i) instanceof Bichinho) {
                processaBichinhos(lolo, elementos, elementos.get(i), tiro);
            }
            else if (elementos.get(i) instanceof Coracao) {
                processaCoracoes(lolo, elementos, elementos.get(i));
            }
            else if (elementos.get(i) instanceof Bau) {
                tempBau = elementos.get(i);
            }
            else if (elementos.get(i) instanceof Ovo) {
                processaOvos(lolo, elementos, elementos.get(i), tiro, lastKeyEvent);
            }
            else if (elementos.get(i) instanceof CaveiraPreta){
                processaBichinhos(lolo, elementos, elementos.get(i), tiro);
            }
            else if (elementos.get(i) instanceof BlocoVerde){
                processaBlocosVerdes(lolo, elementos, elementos.get(i), lastKeyEvent);
            }
            else if (elementos.get(i) instanceof BichinhoPreto){
                processaBichinhos(lolo, elementos, elementos.get(i), tiro);
            }
        }
        Bau tempBau2 = (Bau) tempBau;
        if (lolo.getCoracoes() == 0) {
            assert tempBau2 != null;
            if (!tempBau2.isEnterOpen()) {
                pegouTodosCoracoes(elementos, tempBau);
            }
        }
    }

    public void processaBichinhos(Lolo lolo, ArrayList<Elemento> elementos, Elemento bichinho, ArrayList<Elemento> tiro) {
        if (!tiro.isEmpty()) {
            TiroLolo tiroTemp = (TiroLolo) tiro.get(0);

            if (tiroTemp.getPosicao().igual(bichinho.getPosicao())) {
                Posicao posicao = bichinho.getPosicao();
                elementos.remove(bichinho);
                tiro.remove(tiroTemp);

                Ovo ovo = new Ovo("egg.png");
                ovo.setPosicao(posicao.getLinha(), posicao.getColuna());
                elementos.add(ovo);
            }
        }
        if (lolo.getPosicao().igual(bichinho.getPosicao())) {
            lolo.setVidas(lolo.getVidas() - 1);
            lolo.setPosicao(lolo.getLinhaInicial(), lolo.getColunaInicial());
        }
    }

    public void processaCoracoes(Lolo lolo, ArrayList<Elemento> elementos, Elemento coracao) {
        Coracao coracaoTemp = (Coracao) coracao;
        if (lolo.getPosicao().igual(coracao.getPosicao())) {
            lolo.addTirosDisponiveis(coracaoTemp.getTiros());
            lolo.setCoracoes(lolo.getCoracoes() - 1);
            elementos.remove(coracao);
        }
    }

    public void processaOvos(Lolo lolo, ArrayList<Elemento> elementos, Elemento ovo, ArrayList<Elemento> tiros, int lastKeyEvent) {
        if (lolo.getPosicao().igual(ovo.getPosicao())) {
            if (lastKeyEvent == KeyEvent.VK_UP) {
                ovo.setPosicao(ovo.getPosicao().getLinha() - 1, ovo.getPosicao().getColuna());
            }
            else if (lastKeyEvent == KeyEvent.VK_DOWN) {
                ovo.setPosicao(ovo.getPosicao().getLinha() + 1, ovo.getPosicao().getColuna());
            }
            else if (lastKeyEvent == KeyEvent.VK_LEFT) {
                ovo.setPosicao(ovo.getPosicao().getLinha(), ovo.getPosicao().getColuna() - 1);
            }
            else if (lastKeyEvent == KeyEvent.VK_RIGHT) {
                ovo.setPosicao(ovo.getPosicao().getLinha(), ovo.getPosicao().getColuna() + 1);
            }

            if (!ehPosicaoValida2(elementos, ovo.getPosicao())) {
                ovo.voltaAUltimaPosicao();
            }

            if (!ehPosicaoValidaOvoBlocoVerde(lolo, ovo.getPosicao())) {
                lolo.voltaAUltimaPosicao();
            }
        }
        if (!tiros.isEmpty()) {
            Elemento tiroTemp = tiros.get(0);

            if (tiroTemp.getPosicao().igual(ovo.getPosicao())) {
                elementos.remove(ovo);
                tiros.remove(tiroTemp);
            }
        }
    }

    public void processaBlocosVerdes(Lolo lolo, ArrayList<Elemento> elementos, Elemento blocoVerde, int lastKeyEvent){
        if (lolo.getPosicao().igual(blocoVerde.getPosicao())) {
            if (lastKeyEvent == KeyEvent.VK_UP) {
                blocoVerde.setPosicao(blocoVerde.getPosicao().getLinha() - 1, blocoVerde.getPosicao().getColuna());
            }
            else if (lastKeyEvent == KeyEvent.VK_DOWN) {
                blocoVerde.setPosicao(blocoVerde.getPosicao().getLinha() + 1, blocoVerde.getPosicao().getColuna());
            }
            else if (lastKeyEvent == KeyEvent.VK_LEFT) {
                blocoVerde.setPosicao(blocoVerde.getPosicao().getLinha(), blocoVerde.getPosicao().getColuna() - 1);
            }
            else if (lastKeyEvent == KeyEvent.VK_RIGHT) {
                blocoVerde.setPosicao(blocoVerde.getPosicao().getLinha(), blocoVerde.getPosicao().getColuna() + 1);
            }
            if (!ehPosicaoValida2(elementos, blocoVerde.getPosicao())) {
                blocoVerde.voltaAUltimaPosicao();
                lolo.voltaAUltimaPosicao();
            }

            if (!ehPosicaoValidaDosBlocos(elementos, blocoVerde, blocoVerde.getPosicao())) {
                blocoVerde.voltaAUltimaPosicao();
            }

            if (!ehPosicaoValidaOvoBlocoVerde(lolo, blocoVerde.getPosicao())) {
                lolo.voltaAUltimaPosicao();
            }
        }
    }

    /*Retorna true se a posicao p é válida para Lolo com relacao a todos os personagens no array*/
    public boolean ehPosicaoValida(ArrayList<Elemento> e, Posicao p) {
        Elemento pTemp;
        for(int i = 0; i < e.size(); i++){
            pTemp = e.get(i);            
            if(!pTemp.isbTransponivel())
                if(pTemp.getPosicao().igual(p))
                    return false;
        }        
        return true;
    }

    public boolean ehPosicaoValida2(ArrayList<Elemento> e, Posicao p) {
        Elemento pTemp;
        for(int i = 0; i < e.size(); i++){
            pTemp = e.get(i);
            if(!pTemp.isbTransponivel() && !(e.get(i) instanceof Ovo) && !(e.get(i) instanceof BlocoVerde))
                if(pTemp.getPosicao().igual(p))
                    return false;
        }
        return true;
    }

    public boolean ehPosicaoValidaOvoBlocoVerde(Lolo lolo, Posicao p) {
        return !lolo.getPosicao().igual(p);
    }

    public boolean ehPosicaoValidaDosBlocos(ArrayList<Elemento> elementos, Elemento blocoVerdeAtual, Posicao posicao) {
        for (int i = 0; i < elementos.size(); i++) {
            if (elementos.get(i) instanceof BlocoVerde && elementos.get(i) != blocoVerdeAtual) {
                if (!blocoVerdeAtual.isbTransponivel()) {
                    if (elementos.get(i).getPosicao().igual(posicao)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    public void pegouTodosCoracoes(ArrayList<Elemento> elementos, Elemento bau) {
        Posicao posicauBau = bau.getPosicao();
        elementos.remove(bau);

        Bau umBau = new Bau("bauAberto.png");
        umBau.setPosicao(posicauBau.getLinha(), posicauBau.getColuna());
        umBau.setOpen(true);
        elementos.add(umBau);
    }

    public void entrouNoBauAberto(Lolo lolo, ArrayList<Elemento> elementos, Bau bau) {
        if (lolo.getPosicao().igual(bau.getPosicao()) && bau.getOpen()) {
            Posicao posicaoBau = bau.getPosicao();
            elementos.remove(bau);

            Bau newBau = new Bau("bauAbertoEntrou.png");
            newBau.setPosicao(posicaoBau.getLinha(), posicaoBau.getColuna());
            newBau.setEnterOpen(true);
            elementos.add(newBau);

            MataMonstros(elementos);
        }
    }

    public void MataMonstros(ArrayList<Elemento> elementos) {
        for (int i = 0; i < elementos.size(); i++) {
            if (elementos.get(i) instanceof Bichinho) {
                elementos.remove(elementos.get(i));
                i--;
            }
            else if (elementos.get(i) instanceof Ovo) {
                elementos.remove(elementos.get(i));
                i--;
            }
            else if (elementos.get(i) instanceof CaveiraPreta) {
                elementos.remove(elementos.get(i));
                i--;
            }
            else if (elementos.get(i) instanceof BichinhoPreto) {
                elementos.remove(elementos.get(i));
                i--;
            }
        }
    }
}
