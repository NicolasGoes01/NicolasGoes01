package Modelo;

import java.io.Serializable;

public class Coracao extends Elemento implements Serializable {
    private int tiros;
    public Coracao(String sNomeImagePNG, int tiros) {
        super(sNomeImagePNG);
        this.tiros = tiros;
    }

    public int getTiros() {
        return this.tiros;
    }
}
