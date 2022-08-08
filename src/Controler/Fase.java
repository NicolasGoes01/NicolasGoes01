package Controler;

import Modelo.*;
import Auxiliar.Consts;

import java.util.ArrayList;

public class Fase {
    private int faseAtual;
    private ArrayList<Elemento> elementos;

    public Fase (int fase, int vidas){
        elementos = new ArrayList<Elemento>();
        if (fase == Consts.FASE1){

            faseAtual = 1;

            adicionarLolo(8, 6, 6);

            adicionarBau(3, 6);

            adicionarPorta(1, 6);

            adicionarBichinho(2, 2);
            adicionarBichinho(6, 4);
            adicionarBichinho(6, 8);

            adicionarCoracao(2, 1, 0);
            adicionarCoracao(1, 8, 2);
            adicionarCoracao(1, 11, 0);
            adicionarCoracao(11, 8, 0);
            adicionarCoracao(11, 9, 0);
            adicionarCoracao(11, 2, 0);

            adicionarPlanta(1, 1, "yellowPlant.png");
            adicionarPlanta(3, 1, "yellowPlant.png");
            adicionarPlanta(10, 1, "yellowPlant.png");
            adicionarPlanta(11, 1, "yellowPlant.png");
            adicionarPlanta(2, 8, "yellowPlant.png");
            adicionarPlanta(3, 8, "yellowPlant.png");
            adicionarPlanta(3, 9, "yellowPlant.png");
            adicionarPlanta(4, 9, "yellowPlant.png");
            adicionarPlanta(11, 4, "yellowPlant.png");
            adicionarPlanta(11, 5, "yellowPlant.png");
            adicionarPlanta(10, 5, "yellowPlant.png");
            adicionarPlanta(10, 6, "yellowPlant.png");
            adicionarPlanta(9, 11, "yellowPlant.png");
            adicionarPlanta(10, 10, "yellowPlant.png");
            adicionarPlanta(4, 1, "greenPlant.png");
            adicionarPlanta(7, 1, "greenPlant.png");
            adicionarPlanta(8, 1, "greenPlant.png");
            adicionarPlanta(9, 1, "greenPlant.png");
            adicionarPlanta(8, 2, "greenPlant.png");
            adicionarPlanta(9, 2, "greenPlant.png");
            adicionarPlanta(2, 3, "greenPlant.png");
            adicionarPlanta(3, 3, "greenPlant.png");
            adicionarPlanta(2, 4, "greenPlant.png");
            adicionarPlanta(3, 4, "greenPlant.png");
            adicionarPlanta(1, 9, "greenPlant.png");
            adicionarPlanta(2, 9, "greenPlant.png");
            adicionarPlanta(1, 10, "greenPlant.png");
            adicionarPlanta(2, 10, "greenPlant.png");
            adicionarPlanta(3, 10, "greenPlant.png");
            adicionarPlanta(11, 6, "greenPlant.png");
            adicionarPlanta(11, 7, "greenPlant.png");
            adicionarPlanta(10, 7, "greenPlant.png");
            adicionarPlanta(9, 7, "greenPlant.png");
            adicionarPlanta(11, 10, "greenPlant.png");
            adicionarPlanta(11, 11, "greenPlant.png");
            adicionarPlanta(10, 11, "greenPlant.png");
        }
        else if (fase == Consts.FASE2){
            faseAtual = 2;

            adicionarLolo(11, 11, vidas, 7);

            adicionarBau(1, 1);

            adicionarPorta(1, 7);

            adicionarBichinho(7, 5);

            adicionarCoracao(1, 3, 0);
            adicionarCoracao(1, 7, 0);
            adicionarCoracao(6, 1, 2);
            adicionarCoracao(6, 6, 0);
            adicionarCoracao(8, 11, 0);
            adicionarCoracao(9, 7, 2);
            adicionarCoracao(10, 1, 0);

            adicionarPlanta(2, 10, "yellowPlant.png");
            adicionarPlanta(3, 2, "yellowPlant.png");
            adicionarPlanta(3, 8, "yellowPlant.png");
            adicionarPlanta(4, 2, "yellowPlant.png");
            adicionarPlanta(4, 4, "yellowPlant.png");
            adicionarPlanta(4, 6, "yellowPlant.png");
            adicionarPlanta(5, 1, "yellowPlant.png");
            adicionarPlanta(5, 10, "yellowPlant.png");
            adicionarPlanta(6, 4, "yellowPlant.png");
            adicionarPlanta(6, 9, "yellowPlant.png");
            adicionarPlanta(8, 3, "yellowPlant.png");
            adicionarPlanta(8, 5, "yellowPlant.png");
            adicionarPlanta(8, 6, "yellowPlant.png");
            adicionarPlanta(8, 8, "yellowPlant.png");
            adicionarPlanta(10, 2, "yellowPlant.png");
            adicionarPlanta(11, 1, "yellowPlant.png");
            adicionarPlanta(11, 4, "yellowPlant.png");
            adicionarPlanta(11, 9, "yellowPlant.png");
            adicionarPlanta(1, 2, "greenPlant.png");
            adicionarPlanta(1, 4, "greenPlant.png");
            adicionarPlanta(1, 5, "greenPlant.png");
            adicionarPlanta(1, 6, "greenPlant.png");
            adicionarPlanta(1, 8, "greenPlant.png");
            adicionarPlanta(2, 4, "greenPlant.png");
            adicionarPlanta(2, 6, "greenPlant.png");
            adicionarPlanta(2, 8, "greenPlant.png");
            adicionarPlanta(3, 10, "greenPlant.png");
            adicionarPlanta(4, 8, "greenPlant.png");
            adicionarPlanta(4, 10, "greenPlant.png");
            adicionarPlanta(5, 2, "greenPlant.png");
            adicionarPlanta(5, 6, "greenPlant.png");
            adicionarPlanta(6, 3, "greenPlant.png");
            adicionarPlanta(6, 5, "greenPlant.png");
            adicionarPlanta(6, 7, "greenPlant.png");
            adicionarPlanta(7, 1, "greenPlant.png");
            adicionarPlanta(7, 11, "greenPlant.png");
            adicionarPlanta(8, 4, "greenPlant.png");
            adicionarPlanta(8, 7, "greenPlant.png");
            adicionarPlanta(8, 9, "greenPlant.png");
            adicionarPlanta(8, 10, "greenPlant.png");
            adicionarPlanta(9, 8, "greenPlant.png");
            adicionarPlanta(10, 4, "greenPlant.png");
            adicionarPlanta(10, 6, "greenPlant.png");
            adicionarPlanta(10, 7, "greenPlant.png");
            adicionarPlanta(10, 10, "greenPlant.png");
            adicionarPlanta(11, 2, "greenPlant.png");
            adicionarPlanta(11, 10, "greenPlant.png");

            adicionarCaveiraPreta(3, 5);
            adicionarCaveiraPreta(6, 8);
        } 
        else if (fase == Consts.FASE3) {
            faseAtual = 3;

            adicionarLolo(11, 6, vidas, 6);

            adicionarBau(5, 2);

            adicionarPorta(1, 7);

            adicionarCoracao(1, 8, 0);
            adicionarCoracao(3, 4, 0);
            adicionarCoracao(5, 1, 0);
            adicionarCoracao(5, 3, 0);
            adicionarCoracao(8, 2, 0);
            adicionarCoracao(9, 10, 0);

            adicionarPlanta(1, 4, "yellowPlant.png");
            adicionarPlanta(1, 9, "yellowPlant.png");
            adicionarPlanta(2, 4, "yellowPlant.png");
            adicionarPlanta(2, 5, "yellowPlant.png");
            adicionarPlanta(2, 8, "yellowPlant.png");
            adicionarPlanta(2, 9, "yellowPlant.png");
            adicionarPlanta(4, 2, "yellowPlant.png");
            adicionarPlanta(4, 3, "yellowPlant.png");
            adicionarPlanta(4, 4, "yellowPlant.png");
            adicionarPlanta(5, 5, "yellowPlant.png");
            adicionarPlanta(8, 10, "yellowPlant.png");
            adicionarPlanta(9, 9, "yellowPlant.png");
            adicionarPlanta(10, 9, "yellowPlant.png");
            adicionarPlanta(1, 5, "greenPlant.png");
            adicionarPlanta(1, 6, "greenPlant.png");
            adicionarPlanta(2, 6, "greenPlant.png");
            adicionarPlanta(4, 1, "greenPlant.png");
            adicionarPlanta(4, 5, "greenPlant.png");
            adicionarPlanta(4, 6, "greenPlant.png");
            adicionarPlanta(4, 7, "greenPlant.png");
            adicionarPlanta(4, 9, "greenPlant.png");
            adicionarPlanta(4, 10, "greenPlant.png");
            adicionarPlanta(5, 6, "greenPlant.png");
            adicionarPlanta(8, 9, "greenPlant.png");
            adicionarPlanta(9, 6, "greenPlant.png");
            adicionarPlanta(10, 5, "greenPlant.png");
            adicionarPlanta(11, 9, "greenPlant.png");

            adicionarAgua(5, 4);
            adicionarAgua(6, 4);
            adicionarAgua(7, 4);
            adicionarAgua(8, 4);
            adicionarAgua(9, 4);
            adicionarAgua(10, 4);
            adicionarAgua(7, 5);
            adicionarAgua(8, 5);
            adicionarAgua(9, 5);
            adicionarAgua(8, 6);

            adicionarBlocoVerde(7, 1);
            adicionarBlocoVerde(7, 2);
            adicionarBlocoVerde(7, 3);
            adicionarBlocoVerde(10, 1);
            adicionarBlocoVerde(10, 2);
            adicionarBlocoVerde(10, 3);
            adicionarBlocoVerde(7, 10);

            desenhaBichinhoPreto(1, 1);
        }
    }

    public ArrayList<Elemento> getElementos(){
            return elementos;
    }

    public int getFaseAtual(){
        return faseAtual;
    }

    private void adicionarPlanta(int linha, int coluna, String sNomeImagePNG) {
        Planta planta = new Planta(sNomeImagePNG);
        planta.setPosicao(linha, coluna);
        elementos.add(planta);
    }

    private void adicionarCoracao(int linha, int coluna, int tiros) {
        Coracao coracao = new Coracao("coracao.png", tiros);
        coracao.setPosicao(linha, coluna);
        elementos.add(coracao);
    }

    private void adicionarBichinho(int linha, int coluna) {
        Bichinho bichinho = new Bichinho("bichinho.png");
        bichinho.setPosicao(linha, coluna);
        elementos.add(bichinho);
    }

    private void adicionarPorta(int linha, int coluna) {
        Porta porta = new Porta("porta.png");
        porta.setPosicao(linha, coluna);
        elementos.add(porta);
    }

    private void adicionarBau(int linha, int coluna) {
        Bau bau = new Bau("bau.png");
        bau.setPosicao(linha, coluna);
        elementos.add(bau);
    }

    private void adicionarLolo(int linha, int coluna, int coracoes) {
        Lolo lLolo = new Lolo("lolo.png", linha, coluna, 5, coracoes, 0);
        elementos.add(lLolo);
    }

    private void adicionarLolo(int linha, int coluna, int vidas, int coracoes) {
        Lolo lLolo = new Lolo("lolo.png", linha, coluna, vidas, coracoes, 0);
        elementos.add(lLolo);
    }

    public void adicionarCaveiraPreta(int linha, int coluna) {
        CaveiraPreta caveiraPreta = new CaveiraPreta("caveiraPreta.png");
        caveiraPreta.setPosicao(linha, coluna);
        elementos.add(caveiraPreta);
    }

    public void adicionarAgua(int linha, int coluna) {
        Agua agua = new Agua("agua.png");
        agua.setPosicao(linha, coluna);
        elementos.add(agua);
    }

    public void adicionarBlocoVerde(int linha, int coluna) {
        BlocoVerde blocoVerde = new BlocoVerde("blocoVerde.png");
        blocoVerde.setPosicao(linha, coluna);
        elementos.add(blocoVerde);
    }

    public void desenhaBichinhoPreto(int linha, int coluna) {
        BichinhoPreto bichinhoPreto = new BichinhoPreto("bichinhoPreto.png");
        bichinhoPreto.setPosicao(linha, coluna);
        elementos.add(bichinhoPreto);
    }
}
