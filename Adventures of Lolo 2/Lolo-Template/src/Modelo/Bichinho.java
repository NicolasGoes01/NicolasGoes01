package Modelo;

import java.io.Serializable;

public class Bichinho extends Elemento implements Serializable {
    public Bichinho(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bMortal = true;
        this.bTransponivel = true;
    }
}
