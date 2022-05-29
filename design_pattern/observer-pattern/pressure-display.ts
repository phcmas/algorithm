import { DisplayElement, Observer } from "./subject";
import { WeatherData, NOT_SETTED } from "./weather-data";

export class PressureDisplay implements Observer, DisplayElement {
  private weatherData: WeatherData;
  private pressure: number;

  constructor(weatherData: WeatherData) {
    this.weatherData = weatherData;
    this.pressure = NOT_SETTED;

    this.weatherData.registerObserver(this);
  }

  update(temperature: number, humidity: number, pressure: number): void {
    this.pressure = pressure;
    this.display();
  }

  display(): void {
    console.log(`pressure condition: pressure ${this.pressure}`);
  }
}
