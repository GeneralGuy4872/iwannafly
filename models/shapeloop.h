shapeloop(subject,color,ultra)
  shape *subject;
  truecolor color;
  bool ultra;
  {
  unsigned char bytes[32];
  for (unsigned char n=0;n<subject->inum;n++)
    {
    bytes[n] = (*(subject->bytecode))[n];
    }
  vector3 verts[16];
  for (unsigned char n=0;n<subject->vnum;n++)
    {
    bytes[n] = (*(subject->bytecode))[n];
    }
  unsigned char n = 0; //for loops are not applicable here
  unsigned char mode = 0;
  unsigned char iter = 0;
  glColor4b((CAMERA->format.uv && PLAYER->detects.uv && ultra) ? 0x7F : color.r,(CAMERA->format.uv && PLAYER->detects.uv && ultra) ? 0 : color.g,(CAMERA->format.uv && PLAYER->detects.uv && ultra) ? 0xFF : color.b,color.a);
  while (n < subject->inum)
    {
    switch (mode)
      {
      case 0 :
        {
        mode = bytes[n];
        n++;
        iter = bytes[n];
        n++;
        break;
        }
      case 1 :
        {
        glBegin(GL_POINTS);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 2 :
        {
        glBegin(GL_LINES);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 3 :
        {
        glBegin(GL_TRIANGLES);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
          glCullFace(GL_BACK);
        glEnd();
        mode = 0;
        break;
        }
      case 4 :
        {
        glBegin(GL_QUADS);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
          glCullFace(GL_BACK);
        glEnd();
        mode = 0;
        break;
        }
      case 5 :
        {
        glBegin(GL_POLYGON);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 6 :
        {
        glBegin(GL_LINE_STRIP);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 7 :
        {
        glBegin(GL_TRIANGLE_FAN);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
          glCullFace(GL_BACK);
        glEnd();
        mode = 0;
        break;
        }
      case 8 :
        {
        glBegin(GL_LINE_LOOP);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 9 :
        {
        glBegin(GL_LINES);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[0].x,verts[0].y,verts[0].z);
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 10 :
        {
        glBegin(GL_LINE_LOOP);
          glVertex3f(verts[0].x,verts[0].y,verts[0].z);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      case 12 :
        {
        glBegin(GL_QUAD_STRIP);
          while (iter && (n < subject->inum))
            {
            glVertex3f(verts[(int)bytes[n]].x,verts[(int)bytes[n]].y,verts[(int)bytes[n]].z);
            n++;
            iter--;
            }
        glEnd();
        mode = 0;
        break;
        }
      default :
        {
        FLOW_ERROR_MACRO;
        mode = 0;
        break;
        }
      }
    }
  }

boneloop(subject)
  bone* subject;
  {
  if (subject->drawline)
    {
    shapeloop(shape_line(subject->len.x,subject->len.y,subject->len.z),subject->color,subject->ultraviolet);
    }
  noop();
  if (subject->geom != NULL)
    {
    shapeloop(subject->geom,subject->color,subject->ultraviolet);
    }
  }
