package test;

import javax.tv.xlet.Xlet;
import javax.tv.xlet.XletContext;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.Graphics;

import org.havi.ui.HScene;
import org.havi.ui.HSceneFactory;

public class FirstBDJApp implements Xlet {

    private static Font font;
    private HScene scene;
    private Container gui;
    private String text = "My first BD-J app running on the PS3!";
    //private String text = "My first BD-J app running on " + System.getProperty("os.name");

        public FirstBDJApp() {
    }

    public void initXlet(XletContext context) {

        font = new Font(null, Font.PLAIN, 48);

        scene = HSceneFactory.getInstance().getDefaultHScene();
        gui = new Container() {

            public void paint(Graphics g) {
                g.setFont(font);
                g.setColor(new Color(10, 10, 10));
                g.fillRect(20, 20, getWidth() - 40, getHeight() - 40);
                g.setColor(new Color(245, 245, 245));
                int message_width = g.getFontMetrics().stringWidth(text);
                g.drawString(text, (getWidth() - message_width) / 2, 500);
            }
        };

        gui.setSize(1920, 1080);  
        scene.add(gui, BorderLayout.CENTER);
        scene.validate();
    }

    public void startXlet() {
        gui.setVisible(true);
        scene.setVisible(true);
    }

    public void pauseXlet() {
        gui.setVisible(false);
    }

    public void destroyXlet(boolean unconditional) {
        scene.remove(gui);
        scene = null;
    }
}