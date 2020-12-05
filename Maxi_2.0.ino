/*
Code for line follower using 8 IR array.
*/
const int ma1=2, ma2=3, mb1=4, mb2=5;
int s[8],var,i;
int pw1=200,pw2=200;

void setup() 
{
  for(i=2;i<=5;i++)
  {
    pinMode(i,OUTPUT);
  }
  for(i=22;i<=29;i++)
  {
    pinMode(i,INPUT);
  }
  digitalWrite(ma1,0);
  digitalWrite(ma2,0);
  digitalWrite(mb1,0);
  digitalWrite(mb2,0);
  analogWrite(11,pw1);
  analogWrite(10,pw2);
  delay(5000); 
  
}

void loop() 
{
  for(i=0;i<8;i++)
  {
    s[i]=digitalRead(22+i);
  }
  
  
  if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
  {
    reverse();
  }
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && (s[3] == 0 || s[4] == 0) && s[5] == 1 && s[6] == 1 && s[7] == 1)
  {
    front();

  }
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && (s[5] == 0 || s[6] == 0 ||s[7] == 0))
  {
    right();
  }
  else if ((s[0] == 0 || s[1] == 0 || s[2] == 0 ) && s[5] == 1 && s[6] == 1 && s[7] == 1)
  {
    left();
  }
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
  {
    if (var%2==0)
    {
      right();
    }
    else
    {
      left();
    }
  }
  var+=var;
}

void front()
{
  digitalWrite(ma1,1);
  digitalWrite(ma2,0);
  digitalWrite(mb1,1);
  digitalWrite(mb2,0);
}

void right()
{
  digitalWrite(ma1,1);
  digitalWrite(ma2,0);
  digitalWrite(mb1,0);
  digitalWrite(mb2,1);
}

void left()
{
  digitalWrite(ma1,0);
  digitalWrite(ma2,1);
  digitalWrite(mb1,1);
  digitalWrite(mb2,0);
}
void reverse()
{
  digitalWrite(ma1,0);
  digitalWrite(ma2,1);
  digitalWrite(mb1,0);
  digitalWrite(mb2,1);
}
