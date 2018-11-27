package main.colliders;

import main.entities.Entity;
import main.framework.GameObject;
import main.entities.Bullet;
import main.objects.Block;
import main.window.Handler;

import java.util.LinkedList;

public class BulletCollider extends EntityCollider {

    private transient Bullet bullet;

    public BulletCollider(Entity entity) {
        super(entity);
        bullet = (Bullet)entity;
    }

    public void reinit(GameObject object) {
        super.reinit(object);
        bullet = (Bullet) object;
    }

    @Override
    public void collision(Handler handler) {
        for(int i = 0; i < handler.object.size(); i ++){
            GameObject tempObject = handler.object.get(i);
            if(!(tempObject instanceof Bullet) && intersectsGameObject(this.bullet.getBounds(), tempObject)){
                if(tempObject instanceof Entity) {
                    hit(bullet, (Entity) tempObject, bullet.getFacing());
                    this.bullet.destroy();
                }else if(tempObject instanceof Block) {
                    this.bullet.destroy();
                }
            }
        }
    }
}
