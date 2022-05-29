import { DisplayElement, Observer } from "./subject";
import { WeatherData, NOT_SETTED } from "./weather-data";

export class CurrentConditionsDisplay implements Observer, DisplayElement {
  private temperature: number;
  private humidity: number;
  private weatherData: WeatherData;

  constructor(weatherData: WeatherData) {
    this.weatherData = weatherData;
    this.temperature = NOT_SETTED;
    this.humidity = NOT_SETTED;

    this.weatherData.registerObserver(this);
  }

  update(temperature: number, humidity: number, pressure: number): void {
    this.temperature = temperature;
    this.humidity = humidity;
    this.display();
  }

  display(): void {
    console.log(
      `current condition: temperature ${this.temperature}F, humidity ${this.humidity}`
    );
  }
}
