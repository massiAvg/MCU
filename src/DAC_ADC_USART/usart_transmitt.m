% Define serial port with 115200 baud rate 
rate = 115200;

while(1)
deviceSTM32 = serialport('COM44',rate);

prompt = "Type\nA to insert code 4095 to the DAC\nB to insert code 3000 to the DAC\nC to insert code 2500 to the DAC\nD to insert code 1750 to the DAC\n";
txt = input(prompt,"s");

write(deviceSTM32, txt, "uint8");

while(deviceSTM32.NumBytesAvailable==0)
end
data=char(read(deviceSTM32,deviceSTM32.NumBytesAvailable,"uint8"));
pause(1);

% Close and delete the serial port
delete(deviceSTM32);

end
