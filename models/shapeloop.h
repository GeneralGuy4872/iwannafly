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
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glEnd()
      mode = 0
      }
    else if (mode == 2)
      {
      glBegin(GL_LINES)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glEnd()
      mode = 0
      }
    else if (mode == 3)
      {
      glBegin(GL_TRIANGLES)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter0
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
    else if (mode == 4)
      {
      glBegin(GL_QUADS)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
    else if (mode == 5)
      {
      glBegin(GL_POLYGON)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glEnd()
      mode = 0
      }
    else if (mode == 6)
      {
      glBegin(GL_LINE_STRIP)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glEnd()
      mode = 0
      }
    else if (mode == 7)
      {
      glBegin(GL_TRIANGLE_FAN)
        while (iter && n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glCullFace(GL_BACK)
      glEnd()
      mode = 0
      }
    else if (mode == 8)
      {
      glBegin(GL_LINE_LOOP)
        while (iter && (n < subject.inum))
          {
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      mode = 0
      glEnd()
      }
    else if (mode == 9)
      {
      glBegin(GL_LINES)
        while (iter && n < subject.inum))
          {
          glvertex3f(subject.vertlist[0].x,subject.vertlist[0].y,subject.vertlist[0].z)
          glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
          n++
          iter--
          }
      glEnd()
      mode = 0
      }
    else
      {
        while (iter && (n < subject.inum))
          {
          n++
          iter--
          }
      glEnd()
      mode = 0
<END>

groundloop(subject)
struct shape subject
  {
  unsigned char n = 0
  unsigned char mode = 0
  unsigned char iter = 0
  glColor4b(subject.color.r,subject.color.g,subject.color.b,subject.color.a)
  while (n < subject.inum)
    {
    glBegin(GL_TRIANGLE_FAN)
      while (iter && n < subject.inum))
        {
        glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
        n++
        iter--
        }
    glEnd()
    mode = 0
<END>
