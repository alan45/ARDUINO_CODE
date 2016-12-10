<?xml version="1.0" encoding="UTF-8"?>
<project name="RAM_test" board="Mojo V3" language="Lucid">
  <files>
    <src>pulse2.luc</src>
    <src>pulse.luc</src>
    <src top="true">mojo_top.luc</src>
    <ucf>Teensy3.ucf</ucf>
    <ucf lib="true">mojo.ucf</ucf>
    <component>simple_ram.v</component>
    <component>reset_conditioner.luc</component>
    <component>pipeline.luc</component>
    <component>edge_detector.luc</component>
  </files>
</project>
