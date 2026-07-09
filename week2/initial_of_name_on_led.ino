author piyusha sharma
IOT027
Summer School 26
  
  int rows[] = {2,3,4,5};
int cols[] = {6,7,8,9};


// P letter pattern
int letterP[4][4] =
{
  {1,1,1,0},
  {1,0,0,1},
  {1,1,1,0},
  {1,0,0,0}
};


void setup()
{
  for(int i=0;i<4;i++)
  {
    pinMode(rows[i],OUTPUT);
    pinMode(cols[i],OUTPUT);
  }
}


void loop()
{

  for(int r=0;r<4;r++)
  {

    digitalWrite(rows[r],HIGH);


    for(int c=0;c<4;c++)
    {

      if(letterP[r][c]==1)
      {
        digitalWrite(cols[c],LOW);
      }
      else
      {
        digitalWrite(cols[c],HIGH);
      }

    }


    delay(5);

    digitalWrite(rows[r],LOW);

  }

}
