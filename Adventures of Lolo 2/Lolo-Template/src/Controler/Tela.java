/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Tela.java
 *
 * Created on 03/03/2011, 18:28:20
 */
package Controler;

import Auxiliar.Posicao;
import Modelo.*;
import Auxiliar.Consts;
import Auxiliar.Desenho;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;


public class Tela extends javax.swing.JFrame implements MouseListener, KeyListener {

    private Lolo lLolo;
    private ArrayList<Elemento> elementos;
    private ArrayList<Elemento> lolo;
    private ArrayList<Elemento> caveiraPreta;
    private ArrayList<Elemento> bichinhoPreto;
    private ArrayList<Elemento> tiroLolo;
    private Porta porta;
    private ControleDeJogo cj = new ControleDeJogo();
    private Graphics2D g2;
    private int lastKeyEvent;
    private int faseAtual;
    private boolean telaInicial;
    private boolean variacao;

    private boolean youWin;
    /**
     * Creates new form tabuleiro
     */
    public Tela() {
        Desenho.setCenario(this);
        initComponents();
        this.addMouseListener(this); /*mouse*/

        this.addKeyListener(this);   /*teclado*/
        /*Cria a janela do tamanho do tabuleiro + insets (bordas) da janela*/
        this.setSize(Consts.RES * Consts.CELL_SIDE + getInsets().left + getInsets().right,
                (Consts.RES-1) * Consts.CELL_SIDE + getInsets().top + getInsets().bottom);

        lolo = new ArrayList<Elemento>(1);
        elementos = new ArrayList<Elemento>(200);
        caveiraPreta = new ArrayList<Elemento>(100);
        tiroLolo = new ArrayList<Elemento>(1);
        bichinhoPreto = new ArrayList<Elemento>(10);

        telaInicial = true;
        variacao = true;
        youWin = false;
    }

    public void carregarFase(int pFase) {
        Fase fase;
        if (pFase == 1)
            fase = new Fase(pFase, 5);
        else {
            fase = new Fase(pFase, lLolo.getVidas());
        }
        faseAtual = fase.getFaseAtual();
        carregarElementosDaFase(fase.getElementos());
    }

    public void carregarElementosDaFase(ArrayList<Elemento> elementos) {
        this.elementos = elementos;
        for (int i = 0; i < elementos.size(); i++) {
            if (elementos.get(i) instanceof Lolo) {
                lLolo = (Lolo)elementos.get(i);
                lolo.add(elementos.get(i));
            }
            else if (elementos.get(i) instanceof CaveiraPreta) {
                caveiraPreta.add(elementos.get(i));
            }
            else if (elementos.get(i) instanceof BichinhoPreto) {
                bichinhoPreto.add(elementos.get(i));
            }
            else if (elementos.get(i) instanceof Porta) {
                porta = (Porta) elementos.get(i);
            }
        }
    }

    public void addTiroLolo(TiroLolo umTiroLolo) {
        tiroLolo.add(umTiroLolo);
    }

    public void removeTiroLolo(TiroLolo umTiroLolo) {
        tiroLolo.remove(umTiroLolo);
    }

    public void LimpaTela() {
        elementos.clear();
        lolo.clear();
        caveiraPreta.clear();
        bichinhoPreto.clear();
    }

    public Graphics getGraphicsBuffer(){
        return g2;
    }
    public void paint(Graphics gOld) {
        Graphics g = this.getBufferStrategy().getDrawGraphics();
        /*Criamos um contexto gráfico*/
        g2 = (Graphics2D) g.create(getInsets().left, getInsets().top, getWidth() - getInsets().right, getHeight() - getInsets().top);
        /*************Desenha cenário de fundo**************/
        if (telaInicial) {
            desenharTelaInicial();
        }
        else if (youWin) {
            desenharTelaWin();
        }
        else { //in game
            //printa blocos
            desenhaBlocosBackground();

            //printa paredes
            desenhaParedes();

            //printa menu lateral
            desenhaMenuLateral();

        }

        if (!this.elementos.isEmpty()) {
            this.cj.desenhaTudo(elementos);
            this.cj.processaTudo(lLolo, elementos, tiroLolo, lastKeyEvent);
        }
        if (!caveiraPreta.isEmpty() && lLolo.getCoracoes() == 0) {
            moveCaveiraPreta();
        }
        if (!this.tiroLolo.isEmpty()) {
            this.cj.desenhaTudo(tiroLolo);
        }
        if (!bichinhoPreto.isEmpty()) {
            moveBichinhoPreto();
        }
        if (!this.lolo.isEmpty()) {
            this.cj.desenhaTudo(lolo);
            if (lLolo.getVidas() == 0) {
                LimpaTela();
                carregarFase(Consts.FASE1);
            }
        }

        g.dispose();
        g2.dispose();
        if (!getBufferStrategy().contentsLost()) {
            getBufferStrategy().show();
        }
    }

    private void desenhaMenuLateral() {
        g2.setColor(Color.BLACK);
        g2.fillRect(Consts.WALL * Consts.CELL_SIDE, 0, Consts.CELL_SIDE, Consts.RES*Consts.CELL_SIDE);
        try {
            g2.setColor(Color.WHITE);
            g2.setFont(new Font("Bradley Hand",Font.PLAIN,25));
            Image loloScore = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "lolo_points.png");
            g2.drawImage(loloScore, Consts.WALL * Consts.CELL_SIDE, Consts.CELL_SIDE, Consts.CELL_SIDE, Consts.CELL_SIDE, null);
            g2.drawString(lLolo.getVidas()+"", ((Consts.WALL+1) * Consts.CELL_SIDE)-25, 2.45F*Consts.CELL_SIDE);
            Image coracaoScore = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "tiroLoloEsquerda.png");
            g2.drawImage(coracaoScore, Consts.WALL * Consts.CELL_SIDE, 3 * Consts.CELL_SIDE, Consts.CELL_SIDE, Consts.CELL_SIDE, null);
            g2.drawString(lLolo.getTirosDisponiveis()+"", ((Consts.WALL+1) * Consts.CELL_SIDE)-25, 4.20F * Consts.CELL_SIDE);


        } catch (IOException ex) {
            Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void desenhaParedes() {
        try {
            //desenha menu lateral ao game
            Image parede = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "borda_dir.png");
            g2.drawImage(parede, 12 * Consts.CELL_SIDE, 0, Consts.CELL_SIDE, Consts.WALL*Consts.CELL_SIDE, null);
            parede = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "borda_inf.png");
            g2.drawImage(parede, 0, (Consts.WALL-1)*Consts.CELL_SIDE, Consts.WALL*Consts.CELL_SIDE, Consts.CELL_SIDE, null);
            parede = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "borda_esq.png");
            g2.drawImage(parede, 0, 0, Consts.CELL_SIDE, Consts.WALL*Consts.CELL_SIDE, null);
            parede = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "borda_sub.png");
            g2.drawImage(parede, 0, 0, Consts.WALL*Consts.CELL_SIDE, Consts.CELL_SIDE, null);
        } catch (IOException ex) {
            Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void desenhaBlocosBackground() {
        for (int i = 1; i < Consts.FIELD+1; i++) {
            for (int j = 1; j < Consts.FIELD+1; j++) {
                try {
                    Image bricks = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + "bricks.png");
                    g2.drawImage(bricks, j * Consts.CELL_SIDE, i * Consts.CELL_SIDE, Consts.CELL_SIDE, Consts.CELL_SIDE, null);

                } catch (IOException ex) {
                    Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
                }

            }
        }
    }

    private void desenharTelaWin() {
        try {
            String imagem = "YouWin/you_win.png";
            Image telaInicial = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + imagem);
            g2.drawImage(telaInicial, 0, 0, Consts.RES *Consts.CELL_SIDE, Consts.WALL*Consts.CELL_SIDE, null);
        } catch (IOException ex) {
            Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void desenharTelaInicial() {
        try {
            String imagem = "TelaInicial/tela_inicial.png";
            if (variacao){
                imagem = "TelaInicial/tela_inicial2.png";
            }
            Image telaInicial = Toolkit.getDefaultToolkit().getImage(new File(".").getCanonicalPath() + Consts.PATH + imagem);
            g2.drawImage(telaInicial, 0, 0, Consts.RES *Consts.CELL_SIDE, Consts.RES*Consts.CELL_SIDE, null);
            variacao = !variacao;
        } catch (IOException ex) {
            Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
        }


    }

    public void go() {
        TimerTask task = new TimerTask() {
            public void run() {
                repaint();
            }
        };
        Timer timer = new Timer();
        timer.schedule(task, 0, Consts.PERIOD);
    }

    public void keyPressed(KeyEvent e) {
        if (!telaInicial) {
            if (e.getKeyCode() == KeyEvent.VK_C) {
                LimpaTela();
            } else if (e.getKeyCode() == KeyEvent.VK_L) {
                try {
                    File tanque = new File("POO.zip");
                    FileInputStream canoOut = new FileInputStream(tanque);
                    GZIPInputStream compactador = new GZIPInputStream(canoOut);
                    ObjectInputStream serializador = new ObjectInputStream(compactador);
                    this.lolo = (ArrayList<Elemento>)serializador.readObject();
                    this.elementos = (ArrayList<Elemento>)serializador.readObject();
                    this.caveiraPreta = (ArrayList<Elemento>)serializador.readObject();
                    this.bichinhoPreto = (ArrayList<Elemento>)serializador.readObject();
                    this.lLolo = (Lolo)this.lolo.get(0);
                    serializador.close();
                } catch (Exception ex) {
                    Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
                }
            } else if (e.getKeyCode() == KeyEvent.VK_S) {
                try {
                    File tanque = new File("POO.zip");
                    tanque.createNewFile();
                    FileOutputStream canoOut = new FileOutputStream(tanque);
                    GZIPOutputStream compactador = new GZIPOutputStream(canoOut);
                    ObjectOutputStream serializador = new ObjectOutputStream(compactador);
                    serializador.writeObject(this.lolo);
                    serializador.writeObject(this.elementos);
                    serializador.writeObject(this.caveiraPreta);
                    serializador.writeObject(this.bichinhoPreto);
                    serializador.flush();
                    serializador.close();
                } catch (IOException ex) {
                    Logger.getLogger(Tela.class.getName()).log(Level.SEVERE, null, ex);
                }
            } else if (e.getKeyCode() == KeyEvent.VK_R) {
                LimpaTela();
                youWin = false;
                if (faseAtual == 1) {
                    carregarFase(Consts.FASE1);
                } else if (faseAtual == 2) {
                    carregarFase(Consts.FASE2);
                } else if (faseAtual == 3) {
                    carregarFase(Consts.FASE3);
                }
            } else if (e.getKeyCode() == KeyEvent.VK_M) {
                LimpaTela();
                youWin = false;
                telaInicial = true;
            } else if (e.getKeyCode() == KeyEvent.VK_UP) {
                lLolo.moveUp();
                lastKeyEvent = KeyEvent.VK_UP;
            } else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
                lLolo.moveDown();
                lastKeyEvent = KeyEvent.VK_DOWN;
            } else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
                lLolo.moveLeft();
                lastKeyEvent = KeyEvent.VK_LEFT;
            } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
                lLolo.moveRight();
                lastKeyEvent = KeyEvent.VK_RIGHT;
            } else if (e.getKeyCode() == KeyEvent.VK_SPACE && lLolo.getTirosDisponiveis() > 0) {
                TiroLolo tiro = null;
                if (lastKeyEvent == KeyEvent.VK_UP) {
                    tiro = new TiroLolo("tiroLoloCima.png", lastKeyEvent);
                    tiro.setPosicao(lLolo.getPosicao().getLinha() - 1, lLolo.getPosicao().getColuna());
                }
                else if (lastKeyEvent == KeyEvent.VK_DOWN) {
                    tiro = new TiroLolo("tiroLoloBaixo.png", lastKeyEvent);
                    tiro.setPosicao(lLolo.getPosicao().getLinha() + 1, lLolo.getPosicao().getColuna());
                }
                else if (lastKeyEvent == KeyEvent.VK_LEFT) {
                    tiro = new TiroLolo("tiroLoloEsquerda.png", lastKeyEvent);
                    tiro.setPosicao(lLolo.getPosicao().getLinha(), lLolo.getPosicao().getColuna() - 1);
                }
                else if (lastKeyEvent == KeyEvent.VK_RIGHT) {
                    tiro = new TiroLolo("tiroLoloDireita.png", lastKeyEvent);
                    tiro.setPosicao(lLolo.getPosicao().getLinha(), lLolo.getPosicao().getColuna() + 1);
                }
                if (tiro != null) {
                    this.addTiroLolo(tiro);
                    lLolo.setTirosDisponiveis(lLolo.getTirosDisponiveis() - 1);
                }
            }

            if (!cj.ehPosicaoValida(this.elementos, lLolo.getPosicao())) {
                lLolo.voltaAUltimaPosicao();
            }

            if (lLolo.getCoracoes() == 0) {
                Bau tempBau = null;
                for (int i = 0; i < elementos.size(); i++) {
                    if (elementos.get(i) instanceof Bau) {
                        tempBau = (Bau) elementos.get(i);
                        break;
                    }
                }

                if (lLolo.getPosicao().igual(tempBau.getPosicao()) && tempBau.getOpen()) {
                    this.cj.entrouNoBauAberto(lLolo, elementos, tempBau);
                }

                if (lLolo.getPosicao().igual(porta.getPosicao()) && tempBau.isEnterOpen()) {
                    LimpaTela();
                    if (faseAtual == 1) {
                        carregarFase(Consts.FASE2);
                    }
                    else if (faseAtual == 2) {
                        carregarFase(Consts.FASE3);
                    }
                    else if (faseAtual == 3) {
                        youWin = true;
                    }
                }
            }

            this.setTitle("-> Cell: " + (lLolo.getPosicao().getColuna()) + ", "
                    + (lLolo.getPosicao().getLinha()));
        }

        else {
            if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                telaInicial = false;
                carregarFase(Consts.FASE1);
            }
        }
    }

    public void moveBichinhoPreto() {
        BichinhoPreto bichinhoPretoTemp = (BichinhoPreto) bichinhoPreto.get(0);
        Random move = new Random();
        int moveBichinho = move.nextInt(4);
        Posicao tempPosicao;

        if (moveBichinho == 0) {
            tempPosicao = new Posicao(bichinhoPretoTemp.getPosicao().getLinha(), bichinhoPretoTemp.getPosicao().getColuna() + 1);
        } else if (moveBichinho == 1) {
            tempPosicao = new Posicao(bichinhoPretoTemp.getPosicao().getLinha(), bichinhoPretoTemp.getPosicao().getColuna() - 1);
        } else if (moveBichinho == 2) {
            tempPosicao = new Posicao(bichinhoPretoTemp.getPosicao().getLinha() + 1, bichinhoPretoTemp.getPosicao().getColuna());
        } else {
            tempPosicao = new Posicao(bichinhoPretoTemp.getPosicao().getLinha() - 1, bichinhoPretoTemp.getPosicao().getColuna());
        }

        boolean isValidPosition = true;

        if (!cj.ehPosicaoValida(this.elementos, tempPosicao)) {
            isValidPosition = false;
        }

        if (isValidPosition) {
            bichinhoPretoTemp.setPosicao(tempPosicao.getLinha(), tempPosicao.getColuna());
        }
    }

    public void moveCaveiraPreta() {
        CaveiraPreta caveiraPretaTemp = (CaveiraPreta) caveiraPreta.get(1);
        Random move = new Random();
        int moveCaveira = move.nextInt(4);
        Posicao tempPosicao;

        if (moveCaveira == 0) {
            tempPosicao = new Posicao(caveiraPretaTemp.getPosicao().getLinha(), caveiraPretaTemp.getPosicao().getColuna() + 1);
        } else if (moveCaveira == 1) {
            tempPosicao = new Posicao(caveiraPretaTemp.getPosicao().getLinha(), caveiraPretaTemp.getPosicao().getColuna() - 1);
        } else if (moveCaveira == 2) {
            tempPosicao = new Posicao(caveiraPretaTemp.getPosicao().getLinha() + 1, caveiraPretaTemp.getPosicao().getColuna());
        } else {
            tempPosicao = new Posicao(caveiraPretaTemp.getPosicao().getLinha() - 1, caveiraPretaTemp.getPosicao().getColuna());
        }

        boolean isValidPosition = true;

        if (!cj.ehPosicaoValida(this.elementos, tempPosicao)) {
            isValidPosition = false;
        }

        if (isValidPosition) {
            caveiraPretaTemp.setPosicao(tempPosicao.getLinha(), tempPosicao.getColuna());
        }
    }

    public void mousePressed(MouseEvent e) {
        /* Clique do mouse desligado
         int x = e.getX();
         int y = e.getY();
     
         this.setTitle("X: "+ x + ", Y: " + y +
         " -> Cell: " + (y/Consts.CELL_SIDE) + ", " + (x/Consts.CELL_SIDE));
        
         this.lLolo.getPosicao().setPosicao(y/Consts.CELL_SIDE, x/Consts.CELL_SIDE);
         */
        repaint();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    public void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("POO2015-1 - Adventures of lolo");
        setAutoRequestFocus(false);
        setPreferredSize(new java.awt.Dimension(500, 500));
        setResizable(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 561, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 500, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables

    public void mouseMoved(MouseEvent e) {
    }

    public void mouseClicked(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mouseDragged(MouseEvent e) {
    }

    public void keyTyped(KeyEvent e) {
    }

    public void keyReleased(KeyEvent e) {
    }
}
