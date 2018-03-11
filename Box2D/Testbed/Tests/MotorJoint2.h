// Adapted from MotorJoint.h

#ifndef MOTOR_JOINT_2_H
#define MOTOR_JOINT_2_H

class MotorJoint2 : public Test
{
public:
    MotorJoint2()
    {
        b2Body* ground = NULL;
        {
            b2BodyDef bd;
            ground = m_world->CreateBody(&bd);

            b2EdgeShape shape;
            shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));

            b2FixtureDef fd;
            fd.shape = &shape;

            ground->CreateFixture(&fd);
        }

        b2Body* body1 = NULL;
        {
            b2BodyDef bd;
            bd.type = b2_dynamicBody;
            bd.position.Set(0.0f, 4.0f);
            body1 = m_world->CreateBody(&bd);

            b2CircleShape shape;
            shape.m_radius = 1.0f;

            b2FixtureDef fd;
            fd.shape = &shape;
            fd.friction = 0.6f;
            fd.density = 2.0f;
            body1->CreateFixture(&fd);
        }

        b2Body* body2 = NULL;
        {
            b2BodyDef bd;
            bd.type = b2_dynamicBody;
            bd.position.Set(4.0f, 8.0f);
            body2 = m_world->CreateBody(&bd);

            b2CircleShape shape;
            shape.m_radius = 1.0f;

            b2FixtureDef fd;
            fd.shape = &shape;
            fd.friction = 0.6f;
            fd.density = 2.0f;
            body2->CreateFixture(&fd);
        }

        {
            b2MotorJointDef mjd;
            mjd.Initialize(body1, body2);
            mjd.maxForce = 1000.0f;
            mjd.maxTorque = 1000.0f;
            m_joint = (b2MotorJoint*)m_world->CreateJoint(&mjd);
        }
    }

    static Test* Create()
    {
        return new MotorJoint2;
    }

    b2MotorJoint* m_joint;
};

#endif
