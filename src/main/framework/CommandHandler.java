package main.framework;

import main.colliders.Collider;
import main.entities.TA;
import main.entities.Player;
import main.items.Elixir;
import main.objects.Block;
import main.window.Handler;

import java.awt.*;
import java.util.Queue;

public class CommandHandler {


    private Handler handler;

    public CommandHandler(Handler handler){
        this.handler = handler;
    }

    public String executeCommand(Queue<String> tokens){
        String feedback = "";
        if(!tokens.isEmpty()){
            String commandHead = tokens.poll();
            if(commandHead.equals("MAKE")){
                try {
                    if (tokens.peek().equals("HELP")) {
                        feedback = "Formatting Requirements: make <ID> <type> <x> <y>";
                    } else {
                        feedback = this.make(tokens.poll(),
                                Integer.parseInt(tokens.poll()),
                                Float.parseFloat(tokens.poll()),
                                Float.parseFloat(tokens.poll()));

                    }
                }catch (NullPointerException e){
                    feedback = "<FAIL> Not Enough Arguments, enter \'/make help\' for more information";
                }catch (NumberFormatException e){
                    feedback = "<FAIL> Illegal Argument(s), enter \'/make help\' for more information";
                }
            }
            else if(commandHead.equals("TP")){
                try {
                    if (tokens.peek().equals("HELP")) {
                        feedback = "Formatting Requirements: tp <x> <y>";
                    } else {
                        feedback = this.tp(
                                Float.parseFloat(tokens.poll()),
                                Float.parseFloat(tokens.poll()));

                    }
                }catch (NullPointerException e){
                    feedback = "<FAIL> Not Enough Arguments, enter \'/tp help\' for more information";
                }catch (NumberFormatException e){
                    feedback = "<FAIL> Illegal Argument(s), enter \'/tp help\' for more information";
                }
            }
        }

        return feedback;

    }

    /*
    TODO check if can make object at specified coordinate
     */
    private String make(String id, int type, float x, float y){
        String feedback = String.format("Made %s of type %d at coordinate (%.1f, %.1f)", id, type, x, y);
        if(id.equals("BLOCK")){
            handler.addObject(new Block(x, y, type, ID.Block, handler));
        }else if(id.equals("ELIXIR")){
            handler.addObject(new Elixir(x, y, ID.Elixir, handler));
        }else if(id.equals("MATHIANT")){
            handler.addObject(new TA(x, y, ID.Mathiant, handler));
        } else{
            feedback = "<FAIL> Illegal Object ID, enter \'/make help\' for more information";
        }

        return feedback;
    }

    private String tp(float x, float y){
        String feedback = String.format("Teleported player to coordinate (%.1f, %.1f)", x, y);
        Player tempPlayer = new Player(x, y, ID.Player, handler);
        boolean success = true;
        Rectangle playerBound = new Rectangle((int)x, (int)y, tempPlayer.getWidth(), tempPlayer.getHeight());

        for(int i = 0; i < handler.object.size(); i ++){
            GameObject tempObject = handler.object.get(i);
            if(Collider.intersectsGameObject(playerBound, tempObject)){
                success = false;
            }
        }

        if(success){
            handler.player.setX(x); handler.player.setY(y);
        }else{
            feedback = "<FAIL> Teleport destination is not applicable (possibly contains another object)";
        }

        return feedback;
    }
}
