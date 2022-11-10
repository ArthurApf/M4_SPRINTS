int led[4] = {17, 18, 8, 3};
int ldr = 6;
int ct = 0;
int buz = 37;
int butt1 = 1;
int butt2 = 2;
int vec[99] = {};
int vec_2[4] = {};
float bin(float ldr, float min, float max){
  float bin = 15*(ldr-min)/(max-min);
  return bin;
}


void setup() {
  Serial.begin(115200);
    for(int i=0;i<=4; ++i){
      pinMode(led[i], OUTPUT);
    }
  pinMode(ldr, INPUT);
  pinMode(butt1, INPUT_PULLUP);
  pinMode(butt2, INPUT_PULLUP);
}


void loop() {
  int ldr_val = analogRead(ldr);
  int ldr_bin = bin(ldr_val,8126,64);
  int butt1_pressed = digitalRead(butt1);
  int butt2_pressed = digitalRead(butt2);

  if(butt1_pressed == LOW){
    vec[ct] = ldr_bin;
    ct += 1;
    Serial.println(ldr_bin);
    delay(300);

    if(ldr_bin == 0){
     vec_2[0] = 0;
     vec_2[1] = 0;
     vec_2[2] = 0;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 1){
     vec_2[0] = 0;
     vec_2[1] = 0;
     vec_2[2] = 0;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 2){
     vec_2[0] = 0;
     vec_2[1] = 0;
     vec_2[2] = 1;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 3){
     vec_2[0] = 0;
     vec_2[1] = 0;
     vec_2[2] = 1;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 4){
     vec_2[0] = 0;
     vec_2[1] = 1;
     vec_2[2] = 0;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 5){
     vec_2[0] = 0;
     vec_2[1] = 1;
     vec_2[2] = 0;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 6){
     vec_2[0] = 0;
     vec_2[1] = 1;
     vec_2[2] = 1;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 7){
     vec_2[0] = 0;
     vec_2[1] = 1;
     vec_2[2] = 1;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 8){
     vec_2[0] = 1;
     vec_2[1] = 0;
     vec_2[2] = 0;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 9){
     vec_2[0] = 1;
     vec_2[1] = 0;
     vec_2[2] = 0;
     vec_2[3] = 1;
    } 
    else if(ldr_bin == 10){
     vec_2[0] = 1;
     vec_2[1] = 0;
     vec_2[2] = 1;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 11){
     vec_2[0] = 1;
     vec_2[1] = 0;
     vec_2[2] = 1;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 12){
     vec_2[0] = 1;
     vec_2[1] = 1;
     vec_2[2] = 0;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 13){
     vec_2[0] = 1;
     vec_2[1] = 0;
     vec_2[2] = 1;
     vec_2[3] = 1;
    }
    else if(ldr_bin == 14){
     vec_2[0] = 1;
     vec_2[1] = 1;
     vec_2[2] = 1;
     vec_2[3] = 0;
    }
    else if(ldr_bin == 15){
     vec_2[0] = 1;
     vec_2[1] = 1;
     vec_2[2] = 1;
     vec_2[3] = 1;
    }

    delay(300);

    for(int j=0; j<4; j++){
      digitalWrite(led[j], vec_2[j]);
    }  
    tone(buz,ldr_bin*500,400);
  }

  if(butt2_pressed == LOW){
   for(int k=0; k<=ct-1; ++k){
     Serial.println(vec[k]);

      if(vec[k] == 0){
      vec_2[0] = 0;
      vec_2[1] = 0;
      vec_2[2] = 0;
      vec_2[3] = 0;
      }

      else if(vec[k] == 1){
      vec_2[0] = 0;
      vec_2[1] = 0;
      vec_2[2] = 0;
      vec_2[3] = 1;
      }
      else if(vec[k] == 2){
      vec_2[0] = 0;
      vec_2[1] = 0;
      vec_2[2] = 1;
      vec_2[3] = 0;
      }
      else if(vec[k] == 3){
      vec_2[0] = 0;
      vec_2[1] = 0;
      vec_2[2] = 1;
      vec_2[3] = 1;
      }
      else if(vec[k] == 4){
      vec_2[0] = 0;
      vec_2[1] = 1;
      vec_2[2] = 0;
      vec_2[3] = 0;
      }
      else if(vec[k] == 5){
      vec_2[0] = 0;
      vec_2[1] = 1;
      vec_2[2] = 0;
      vec_2[3] = 1;
      }
      else if(vec[k] == 6){
      vec_2[0] = 0;
      vec_2[1] = 1;
      vec_2[2] = 1;
      vec_2[3] = 0;
      }
      else if(vec[k] == 7){
      vec_2[0] = 0;
      vec_2[1] = 1;
      vec_2[2] = 1;
      vec_2[3] = 1;
      }
      else if(vec[k] == 8){
      vec_2[0] = 1;
      vec_2[1] = 0;
      vec_2[2] = 0;
      vec_2[3] = 0;
      }
      else if(vec[k] == 9){
      vec_2[0] = 1;
      vec_2[1] = 0;
      vec_2[2] = 0;
      vec_2[3] = 1;
      } 
      else if(vec[k] == 10){
      vec_2[0] = 1;
      vec_2[1] = 0;
      vec_2[2] = 1;
      vec_2[3] = 0;
      }
      else if(vec[k] == 11){
      vec_2[0] = 1;
      vec_2[1] = 0;
      vec_2[2] = 1;
      vec_2[3] = 1;
      }
      else if(vec[k] == 12){
      vec_2[0] = 1;
      vec_2[1] = 1;
      vec_2[2] = 0;
      vec_2[3] = 0;
      }
      else if(vec[k] == 13){
      vec_2[0] = 1;
      vec_2[1] = 0;
      vec_2[2] = 1;
      vec_2[3] = 1;
      }
      else if(vec[k] == 14){
      vec_2[0] = 1;
      vec_2[1] = 1;
      vec_2[2] = 1;
      vec_2[3] = 0;
      }
      else if(vec[k] == 15){
      vec_2[0] = 1;
      vec_2[1] = 1;
      vec_2[2] = 1;
      vec_2[3] = 1;
      }

      for(int n=0; n<4; ++n){
        digitalWrite(led[n], vec_2[n]);
      }  
      tone(buz,vec[k]*500,400);
      vec[k] = 0;
      delay(1000);
   }

    ct = 0;
    
  }
}