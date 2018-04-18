
String line = "Precipitation 0%\n";
void setup() {
  // put your setup code here, to run once:
Serial1.begin(9600);
}

void loop() {

for(int i=14;i<line.length();i++)
{
delay(1000);
Serial1.write(line.charAt(i));
}
}
