package Modelo;

import java.io.Serializable;

public class Ovo extends Elemento implements Serializable {
    public Ovo(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = true;
    }
}
