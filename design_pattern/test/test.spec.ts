import { MallardDuck, ModelDuck, RubberDuck } from "../strategy-pattern/duck";
import { FlyRocketPowered } from "../strategy-pattern/fly-behavior";
import { WeatherData } from "../observer-pattern/weather-data";
import { CurrentConditionsDisplay } from "../observer-pattern/current-conditions-display";
import { PressureDisplay } from "../observer-pattern/pressure-display";
import { RemoteControl } from "../command-pattern/remote-control";
import { CeilingFan, Light, Stereo } from "../command-pattern/devices";
import {
  CeilingFanHighCommand,
  CeilingFanLowCommand,
  CeilingFanOffCommand,
  LightOffCommand,
  LightOnCommand,
  StereoOffCommand,
  StereoOnCommand,
} from "../command-pattern/commands";

describe("common utility test", () => {
  it("strategy pattern", () => {
    const mallard = new MallardDuck();
    mallard.display();
    mallard.performFly();
    mallard.performQuack();

    const model = new ModelDuck();
    model.performFly();
    model.performQuack();
    model.setFlyBehavior(new FlyRocketPowered());
    model.performFly();

    const rubber = new RubberDuck();
    rubber.performFly();
    rubber.performQuack();
  });

  it("observer pattern", () => {
    const weatherData = new WeatherData();

    const currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
    const pressureDisplay = new PressureDisplay(weatherData);

    weatherData.setMesurements(80, 65, 30.4);
    weatherData.setMesurements(60, 30, 15.4);
    weatherData.setMesurements(100, 40, 30.4);
  });

  it("command pattern", () => {
    const remoteControl = new RemoteControl();

    const light = new Light("Living Room");
    const stereo = new Stereo("Kitchen");
    const ceilingFan = new CeilingFan("Living Room");

    const lightOn = new LightOnCommand(light);
    const lightOff = new LightOffCommand(light);
    const stereoOn = new StereoOnCommand(stereo);
    const stereoOff = new StereoOffCommand(stereo);
    const ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
    const ceilingFanLow = new CeilingFanLowCommand(ceilingFan);
    const ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

    remoteControl.setCommand(0, lightOn, lightOff);
    remoteControl.setCommand(1, stereoOn, stereoOff);
    remoteControl.setCommand(2, ceilingFanHigh, ceilingFanOff);
    remoteControl.setCommand(3, ceilingFanLow, ceilingFanOff);

    remoteControl.pressOnButton(0);
    remoteControl.pressOffButton(0);
    remoteControl.pressUndoButtion();

    remoteControl.pressOnButton(1);
    remoteControl.pressOffButton(1);
    remoteControl.pressUndoButtion();

    remoteControl.pressOnButton(2);
    remoteControl.pressOffButton(2);
    remoteControl.pressUndoButtion();

    remoteControl.pressOnButton(3);
    remoteControl.pressOffButton(3);
    remoteControl.pressUndoButtion();
  });
});
