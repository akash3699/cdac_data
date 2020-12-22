import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NoShowComponent } from './no-show.component';

describe('NoShowComponent', () => {
  let component: NoShowComponent;
  let fixture: ComponentFixture<NoShowComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NoShowComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NoShowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
