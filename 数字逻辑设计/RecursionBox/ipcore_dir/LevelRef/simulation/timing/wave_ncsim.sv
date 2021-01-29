
 
 
 

 



window new WaveWindow  -name  "Waves for BMG Example Design"
waveform  using  "Waves for BMG Example Design"


      waveform add -signals /LevelRef_tb/status
      waveform add -signals /LevelRef_tb/LevelRef_synth_inst/bmg_port/CLKA
      waveform add -signals /LevelRef_tb/LevelRef_synth_inst/bmg_port/ADDRA
      waveform add -signals /LevelRef_tb/LevelRef_synth_inst/bmg_port/DINA
      waveform add -signals /LevelRef_tb/LevelRef_synth_inst/bmg_port/WEA
      waveform add -signals /LevelRef_tb/LevelRef_synth_inst/bmg_port/DOUTA
console submit -using simulator -wait no "run"
