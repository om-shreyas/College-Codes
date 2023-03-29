import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class EventHandling extends Applet implements ActionListener{

    Label l;
    Button b;
    public void init(){
        l = new Label("This is a label");
        b = new Button();
        add(l);
        add(b);
        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
        l.setText("Button Pressed");
    }
}
/*
<applet code="EventHandling" width=300 height=300>
</applet>
 */