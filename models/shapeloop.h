shapeloop(subject)
struct shape subject
  {
  unsigned char n = 0
  unsigned char mode = 0
  unsigned char iter = 0
  glColor4b(subject.color.r,subject.color.g,subject.color.b,subject.color.a)
  while (n < subject.inum)
    {
    if !(mode)
      {
      mode = subject.bytecode[n]
      n++
      iter = subject.bytecode[n]
      n++
      }
    else if (mode == 1)
      {
      glBegin(GL_POINTS)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      glEnd()
      mode = 0
      }
    else if (mode == 2)
      {
      glBegin(GL_LINES)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      glEnd()
      mode = 0
      }
    else if (mode == 3)
      {
      glBegin(GL_TRIANGLES)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
    else if (mode == 4)
      {
      glBegin(GL_QUADS)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)          n++
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
    else if (mode == 5)
      {
      glBegin(GL_POLYGON)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      glEnd()
      mode = 0
      }
    else if (mode == 6)
      {
      glBegin(GL_LINE_LOOP)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      mode = 0
      glEnd()
      }
    else if (mode == 7)
      {
      glBegin(GL_GL_TRIANGLE_FAN)
        while iter
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
