/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Modelo;

import java.io.Serializable;


public class Lolo extends Elemento implements Serializable{
    private int vidas;
    private int linhaInicial;
    private int colunaInicial;
    private int coracoes;
    private int tirosDisponiveis;
    public Lolo(String sNomeImagePNG, int linhaInicial, int colunaInicial, int vidas, int coracoes, int tirosDisponiveis) {
        super(sNomeImagePNG);
        this.linhaInicial = linhaInicial;
        this.colunaInicial = colunaInicial;
        this.vidas = vidas;
        this.coracoes = coracoes;
        this.tirosDisponiveis = tirosDisponiveis;
        super.setPosicao(linhaInicial, colunaInicial);
    }

    public void setVidas(int vidas){
        this.vidas = vidas;
    }
    public int getVidas(){
        return this.vidas;
    }
    public void setTirosDisponiveis(int tirosDisponiveis) {
        this.tirosDisponiveis = tirosDisponiveis;
    }
    public int getTirosDisponiveis(){
        return this.tirosDisponiveis;
    }
    public void addTirosDisponiveis(int tirosDisponiveis) {
        this.tirosDisponiveis += tirosDisponiveis;
    }

    public int getCoracoes() {
        return coracoes;
    }

    public void setCoracoes(int coracoes) {
        this.coracoes = coracoes;
    }

    public int getLinhaInicial() {
        return linhaInicial;
    }

    public int getColunaInicial() {
        return colunaInicial;
    }
}
