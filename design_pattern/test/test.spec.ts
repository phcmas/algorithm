import { MallardDuck, ModelDuck, RubberDuck } from "../strategy-pattern/duck";
import { FlyRocketPowered } from "../strategy-pattern/fly-behavior";
import { WeatherData } from "../observer-pattern/weather-data";
import { CurrentConditionsDisplay } from "../observer-pattern/current-conditions-display";
import { PressureDisplay } from "../observer-pattern/pressure-display";

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
});
