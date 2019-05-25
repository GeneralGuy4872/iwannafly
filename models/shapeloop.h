shapeloop(subject)
struct shape subject
  {
  unsigned char inum = 0
  unsigned char vnum = 0
  unsigned char n = 0
  glColor4b(subject.color.r,subject.color.g,subject.color.b,subject.color.a)
  while ((inum < subject.n_poly) && (vnum < subject.n_vert))
    {
    if (subject.mode[inum] < 0)
      {
      glBegin(GL_LINES)
        glVertex3f(subject.poly[vnum + subject.mode[inum]].x,subject.poly[vnum + subject.mode[inum]].y,subject.poly[vnum + subject.mode[inum]].z)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
      glEnd()
      vnum++
      inum++
      }
    else if (subject.mode[inum] == 0)
      {
      glBegin(GL_LINES)
        glVertex3f(subject.poly[0].x,subject.poly[0].y,subject.poly[0].z)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
      glEnd()
      vnum++
      inum++
      }
    else if (subject.mode[inum] == 1)
      {
      glBegin(GL_POINTS)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
      glEnd()
      vnum++
      inum++
      }
      else if (subject.mode[inum] == 2)
      {
      glBegin(GL_LINES)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
        glvertex3f(subject.poly[vnum+1].x,subject.poly[vnum+1].y,subject.poly[vnum+1].z)
      glEnd()
      vnum = vnum + inum
      inum++
      }
      else if (subject.mode[inum] == 3)
      {
      glBegin(GL_TRIANGLES)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
        glvertex3f(subject.poly[vnum+1].x,subject.poly[vnum+1].y,subject.poly[vnum+1].z)
        glvertex3f(subject.poly[vnum+2].x,subject.poly[vnum+2].y,subject.poly[vnum+2].z)
        glCullFace(GL_BACK)
      glEnd()
      vnum = vnum + inum
      inum++
      }
      else if (subject.mode[inum] == 4)
      {
      glBegin(GL_QUADS)
        glvertex3f(subject.poly[vnum].x,subject.poly[vnum].y,subject.poly[vnum].z)
        glvertex3f(subject.poly[vnum+1].x,subject.poly[vnum+1].y,subject.poly[vnum+1].z)
        glvertex3f(subject.poly[vnum+2].x,subject.poly[vnum+2].y,subject.poly[vnum+2].z)
        glvertex3f(subject.poly[vnum+3].x,subject.poly[vnum+3].y,subject.poly[vnum+3].z)
        glCullFace(GL_BACK)
      glEnd()
      vnum = vnum + inum
      inum++
      }
      else if (subject.mode[inum] > 4)
      {
      glBegin(GL_POLYGON)
        while (n < inum)
        {
        glvertex3f(subject.poly[vnum+n].x,subject.poly[vnum+n].y,subject.poly[vnum+n].z)
        }
        n = 0
      glEnd()
      vnum = vnum + inum
      inum++
      }
    }
  }
