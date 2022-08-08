package Modelo;

import java.io.Serializable;

public class BlocoVerde extends Elemento implements Serializable {
    public BlocoVerde(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = true;
    }
}
