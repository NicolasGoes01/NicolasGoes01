package Modelo;

import java.io.Serializable;

public class CaveiraPreta extends Elemento implements Serializable {
    public CaveiraPreta(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = true;
    }
}
